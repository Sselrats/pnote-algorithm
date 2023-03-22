#include <iostream>
using namespace std;

int tile[4][3][2] =
    {{{0, 0}, {1, 0}, {0, 1}},
     {{0, 0}, {1, 0}, {1, 1}},
     {{0, 0}, {0, 1}, {1, 1}},
     {{0, 0}, {1, 0}, {1, -1}}};

bool can_fill(int arr[][21], int H, int W, int x, int y)
{
    return 0 <= x && x < H && 0 <= y && y < W && arr[x][y] == 1;
}

bool chk(int arr[][21], int H, int W, int x, int y, int tile_type)
{
    for (int j = 0; j < 3; j++)
    {
        if (!can_fill(arr, H, W, x + tile[tile_type][j][0], y + tile[tile_type][j][1]))
            return false;
    }
    return true;
}

bool is_filled(int arr[][21], int H, int W)
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (arr[i][j] == 1)
                return false;
        }
    }
    return true;
}

int answer(int arr[][21], int H, int W)
{
    if (is_filled(arr, H, W))
        return 1;

    int refx = -1, refy = -1;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (arr[i][j] == 1)
            {
                refx = i;
                refy = j;
                break;
            }
        }
        if (refx != -1)
            break;
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (chk(arr, H, W, refx, refy, i))
        {
            for (int j = 0; j < 3; j++)
            {
                arr[refx + tile[i][j][0]][refy + tile[i][j][1]] = 0;
            }
            ans += answer(arr, H, W);
            for (int j = 0; j < 3; j++)
            {
                arr[refx + tile[i][j][0]][refy + tile[i][j][1]] = 1;
            }
        }
    }
    return ans;
}

void solve()
{
    int h, w;
    int board[21][21] = {};
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c;
            cin >> c;
            board[i][j] = c == '.' ? 1 : 0;
        }
    }
    cout << answer(board, h, w) << "\n";
}

int main()
{
    int C;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        solve();
    }
}