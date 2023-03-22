#include <iostream>
#include <cstring>
using namespace std;
void solve();
long ans[110];
long temp[110][110];
long MOD = 10000000;

int main()
{
    int C;
    cin >> C;
    solve();
    while (C--)
    {
        int n;
        cin >> n;
        cout << (ans[n]) % MOD << "\n";
    }
}

void solve()
{
    ans[0] = 1;
    ans[1] = 1;
    temp[0][0] = 1;
    temp[1][1] = 1;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= i - j; k++)
            {
                temp[i][j] += (temp[i - j][k] * (j + k - 1)) % MOD;
            }
            if (j == i)
            {
                temp[i][j] = 1;
            }
            ans[i] = (ans[i] + temp[i][j]) % MOD;
        }
    }
}