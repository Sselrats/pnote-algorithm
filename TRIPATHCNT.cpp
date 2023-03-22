#include <iostream>
#include <cstring>
using namespace std;
void solve();
int a[100][100];
int N;
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
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> a[i][j];
        }
    }

    int value[100][100];
    int count[100][100];
    memset(value, -1, sizeof(value));
    memset(count, 0, sizeof(count));

    for (int i = N - 1; i > -1; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (i == N - 1)
            {
                value[i][j] = a[i][j];
                count[i][j] = 1;
                continue;
            }
            if (value[i + 1][j] == value[i + 1][j + 1])
            {
                value[i][j] = value[i + 1][j] + a[i][j];
                count[i][j] = count[i + 1][j] + count[i + 1][j + 1];
                continue;
            }
            if (value[i + 1][j] > value[i + 1][j + 1])
            {
                value[i][j] = value[i + 1][j] + a[i][j];
                count[i][j] = count[i + 1][j];
                continue;
            }
            if (value[i + 1][j] < value[i + 1][j + 1])
            {
                value[i][j] = value[i + 1][j + 1] + a[i][j];
                count[i][j] = count[i + 1][j + 1];
                continue;
            }
        }
    }
    cout << count[0][0] << "\n";
}