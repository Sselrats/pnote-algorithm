#include <iostream>
#include <cstring>
using namespace std;
void solve();
double ans(int n, int m);
double a[1001][1001];
int main()
{
    int C;
    cin >> C;

    cout << fixed;
    cout.precision(10);

    while (C--)
    {
        solve();
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    cout << ans(m, n) << "\n";
}
double ans(int m, int n)
{
    if (a[m][n] != 0)
    {
        return a[m][n];
    }
    if (n == 0)
    {
        return a[m][n] = 1;
    }
    if (m == 0)
    {
        return a[m][n] = 0;
    }
    if (2 * m < n)
    {
        return a[m][n] = 0;
    }
    if (m >= n)
    {
        return a[m][n] = 1;
    }
    return a[m][n] = (ans(m - 1, n - 2) * 3 + ans(m - 1, n - 1)) / (double)4;
}