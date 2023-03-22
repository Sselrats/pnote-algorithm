#include <iostream>
using namespace std;
int board[101][101];
void solve();
bool IsAble(int a, int b);
int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        solve();
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }
    IsAble(n, n) ? cout << "YES"
                        << "\n"
                 : cout << "NO"
                        << "\n";
}
bool IsAble(int a, int b)
{
    if (a == 1 && b == 1)
    {
        return true;
    }
    for (int i = a - 1; i > 0; i--)
    {
        if (board[i][b] == a - i)
        {
            if (IsAble(i, b))
            {
                return true;
            }
        }
    }
    for (int j = b - 1; j > 0; j--)
    {
        if (board[a][j] == b - j)
        {
            if (IsAble(a, j))
            {
                return true;
            }
        }
    }
    return false;
}