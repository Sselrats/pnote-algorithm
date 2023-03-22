#include <iostream>
#include <string.h>
using namespace std;

int C, n, m;
int a[11][11] = {};
int used[11] = {};

void solve();
int rec(int arr[], int size);

int main()
{
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        solve();
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int p, q;
        cin >> p >> q;

        a[p][q] = 1;
        a[q][p] = 1;
    }

    cout << rec(used, n) << "\n";

    memset(used, 0, sizeof(used));
    memset(a, 0, sizeof(a));
}

int rec(int arr[], int size)
{
    int ans = 0, P = -1;

    if (size % 2 == 1)
        return 0;
    else if (size == 0)
        return 1;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
                continue;
            if (P == -1)
                P = i;
            else
            {
                if (a[P][i] == 1)
                {
                    int temparr[11];
                    copy(arr, arr + n, temparr);
                    temparr[i] = 1;
                    temparr[P] = 1;
                    ans += rec(temparr, size - 2);
                }
            }
        }
        return ans;
    }
}
