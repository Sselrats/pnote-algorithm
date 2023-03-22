#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void solve();
int n, m;
const int MAX_V = 10000;
vector<pair<int, double>> adj[MAX_V];

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
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        adj[i].clear();
    }

    int a, b;
    double c;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    vector<double> dist(n, numeric_limits<double>::max());
    dist[0] = 1.0;
    priority_queue<pair<double, int>> pq;
    pq.push(make_pair(-1.0, 0));

    while (!pq.empty())
    {
        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost)
            continue;

        for (vector<pair<int, double>>::iterator iter = adj[here].begin(); iter != adj[here].end(); ++iter)
        {
            pair<int, double> edge = *iter;
            int target = edge.first;
            double nextDist = cost * edge.second;

            if (dist[target] > nextDist)
            {
                dist[target] = nextDist;
                pq.push(make_pair(-nextDist, target));
            }
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << dist[n - 1] << '\n';
}