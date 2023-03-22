#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
void solve();
int ans(int q, int i);
int minfromrange(int start, int end);
int a[100];
int suma[100];
int chkans[11][101];
int chkmfr[101][101];
int n, s;
int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        memset(a, 0, sizeof(a));
        memset(suma, 0, sizeof(suma));
        memset(chkans, -1, sizeof(chkans));
        memset(chkmfr, -1, sizeof(chkmfr));
        solve();
    }
}
void solve()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    suma[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        suma[i] = suma[i - 1] + a[i];
    }
    cout << ans(0, 0) << "\n";
}

int ans(int q, int start)
{
    int answer = 100000010;
    if (chkans[q][start] != -1)
    {
        return chkans[q][start];
    }

    if (start >= n)
    {
        return chkans[q][start] = 0;
    }

    if (q >= s)
    {
        return chkans[q][start] = answer;
    }

    for (int end = start; end < n; end++)
    {
        answer = min(answer, minfromrange(start, end) + ans(q + 1, end + 1));
    }
    return chkans[q][start] = answer;
}

int minfromrange(int start, int end)
{
    if (chkmfr[start][end] != -1)
    {
        return chkmfr[start][end];
    }
    int n = end - start + 1;
    int st = start == 0 ? 0 : suma[start - 1];
    int sum = suma[end] - st;
    int q = round((double)sum / n);
    int r = 0;
    for (int i = start; i < end + 1; i++)
    {
        r += a[i] * a[i];
    }
    r -= 2 * sum * q;
    r += q * q * n;
    return chkmfr[start][end] = r;
}