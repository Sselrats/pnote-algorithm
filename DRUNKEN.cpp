#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> Pair;
void solve();
int v, e;
Pair delay[501];
Pair dist[502][502];
int t;
int main()
{
    fill(dist[0], dist[501], make_pair(987654321, 987654321));

    cin >> v >> e;
    for (int i = 1; i <= v; i++)
    {
        int d;
        cin >> d;
        delay[i] = make_pair(d, i);
        dist[i][i] = make_pair(0, 0);
    }
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int small = min(c, dist[a][b].first);
        dist[a][b] = make_pair(small, small);
        dist[b][a] = make_pair(small, small);
    }
    cin >> t;
    solve();
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << dist[a][b].second << "\n";
        // cout << dist[a][b].first << dist[a][b].second << "\n";
    }
}

void solve()
{
    sort(delay + 1, delay + v + 1);

    for (int kk = 1; kk <= v; kk++)
    {
        int k = delay[kk].second;
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (dist[i][j].first > dist[i][k].first + dist[k][j].first)
                {
                    dist[i][j].first = dist[i][k].first + dist[k][j].first;
                    dist[i][j].second = min(dist[i][j].second, dist[i][k].first + dist[k][j].first + delay[kk].first);
                }

                // int original_time = dist_to_time(dist[i][j]);

                // int current_delay = delay[k];

                // Pair new_dist = make_pair(dist[i][k].first + dist[k][j].first, current_delay);

                // int new_time = dist_to_time(new_dist);

                // if (original_time > new_time)
                // {
                //     dist[i][j] = new_dist;
                // }
                // if (original_time == new_time)
                // {
                //     if (dist[i][j].second < current_delay)
                //     {
                //         dist[i][j] = new_dist;
                //     }
                // }
            }
        }
    }
}