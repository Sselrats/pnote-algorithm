#include <iostream>
#include <algorithm>
using namespace std;

int a[100][100];
void solve();
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

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
            if (i != 0)
            {
                if (j == 0)
                {
                    a[i][j] += a[i - 1][j];
                }
                else if (j == i)
                {
                    a[i][j] += a[i - 1][j - 1];
                }
                else
                {
                    a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
                }
            }
            if (i == n - 1)
            {
                ans = ans < a[i][j] ? a[i][j] : ans;
            }
        }
    }

    cout << ans << "\n";
}