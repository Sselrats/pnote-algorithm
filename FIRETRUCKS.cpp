#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
typedef pair<int, int> Pair;
typedef set<int> Set;
vector<Pair> adj[1000];
vector<int> fire;
map<int, Set> ans;

int v, e, n, m;

void solve();
vector<int> dijkstra(int start);

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
    cin >> v >> e >> n >> m;

    for (int i = 0; i < v; ++i)
    {
        adj[i].clear();
    }
    fire.clear();
    ans.clear();

    int a, b, t;
    while (e--)
    {
        cin >> a >> b >> t;
        adj[a - 1].push_back(make_pair(b - 1, t));
        adj[b - 1].push_back(make_pair(a - 1, t));
    }

    set<int> blank;
    for (int i = 0; i < n; i++)
    {
        int f;
        cin >> f;
        fire.push_back(f - 1);
        ans[f - 1] = blank;
    }

    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;
        vector<int> dist = dijkstra(s - 1);

        for (vector<int>::iterator iter = fire.begin(); iter != fire.end(); iter++)
        {
            int fire_place = *iter;
            ans[fire_place].insert(dist[fire_place]);
        }
    }
    int answer = 0;
    for (vector<int>::iterator iter = fire.begin(); iter != fire.end(); iter++)
    {
        int fire_place = *iter;
        answer += *(ans[fire_place].begin());
    }
    cout << answer << "\n";
}

vector<int> dijkstra(int start)
{
    vector<int> dist(v, numeric_limits<int>::max());
    dist[start] = 0;
    priority_queue<Pair> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost)
            continue;

        for (vector<Pair>::iterator iter = adj[here].begin(); iter != adj[here].end(); ++iter)
        {
            Pair edge = *iter;
            int target = edge.first;
            int nextDist = cost + edge.second;

            if (dist[target] > nextDist)
            {
                dist[target] = nextDist;
                pq.push(make_pair(-nextDist, target));
            }
        }
    }
    return dist;
}