// #include <iostream>
// #include <cstring>
// using namespace std;
// int MAX = 100010;
// int a[500];
// void solve();
// int ans[500];
// int dp[500][500];
// int Count(int index);
// int main()
// {
//     int C;
//     cin >> C;
//     while (C--)
//     {
//         solve();
//     }
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     int answer = 0;
//     memset(ans, 0, sizeof(ans));
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         int cnt = Count(i);
//         if (ans[cnt] == 0)
//         {
//             answer += 1;
//             ans[cnt] = 1;
//         }
//     }
//     cout << answer << "\n";
// }

// int Count(int index)
// {
//     int ans = 0;
//     int chk[500000];
//     memset(chk, 0, sizeof(chk));
//     for (int i = 0; i < index; i++)
//     {
//         if (chk[a[i]] == 0 && a[i] < a[index])
//         {
//             chk[a[i]] = 1;
//             ans++;
//         }
//     }
//     return ans;
// }

#include <iostream>
#include <cstring>
using namespace std;
int dp[1001];
int arr[1001];
void solve();
int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        memset(dp, 0, sizeof(dp));
        memset(arr, 0, sizeof(dp));
        solve();
    }
}
void solve()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}
