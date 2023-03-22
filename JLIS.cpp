#include <iostream>
#include <cstring>
using namespace std;
int dp1[1001];
int dp2[1001];
int arr1[1001];
int arr2[1001];
void solve();
int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        memset(dp, 0, sizeof(dp));
        memset(arr1, 0, sizeof(arr1));
        memset(arr1, 0, sizeof(arr2));

        solve();
    }
}
void solve()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr1[i];
        dp1[i] = 1;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> arr2[i];
        dp2[i] = 1;
    }

    int ans = 1;
    int current = arr1[0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr1[i] > arr1[j])
            {

                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
        ans = max(ans, dp1[i]);
    }

    cout << ans << "\n";
}
