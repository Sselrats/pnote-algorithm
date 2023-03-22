#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve();
int dist[201][201];
int ans;
int v, m, n;
int check_is_valid(int a, int b, int c);
int main()
{
    int c;
    cin >> c;
    while (c--)
    {
        solve();
    }
}

void solve()
{
    ans = 0;
    fill(dist[0], dist[200], 987654321);

    cin >> v >> m >> n;
    for (int i = 0; i < v; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int min_dist = min(dist[a][b], c);
        dist[a][b] = dist[b][a] = min_dist;
    }
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ans += check_is_valid(a, b, c);
    }
    cout << ans << "\n";
}

int check_is_valid(int a, int b, int c)
{
    if (c < dist[a][b])
    {
        dist[a][b] = c;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (dist[i][j] > dist[i][a] + c + dist[b][j])
                {
                    dist[i][j] = dist[i][a] + c + dist[b][j];
                }
                if (dist[i][j] > dist[i][b] + c + dist[a][j])
                {
                    dist[i][j] = dist[i][b] + c + dist[a][j];
                }
            }
        }

        return 0;
    }

    return 1;
}