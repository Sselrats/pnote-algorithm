#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PAST_FUTURE_PAIR;
typedef pair<PAST_FUTURE_PAIR, int> WORMHOLE_PAIR;
typedef vector<WORMHOLE_PAIR> WORMHOLE_PAIRS;

const int INF = 2147483647;

int galaxy, wormhole;
vector<WORMHOLE_PAIRS> adj;

void solve();
void bellman_ford();
bool find_vertex(int here, int find, vector<bool> &visited);
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
    cin >> galaxy >> wormhole;
    adj = vector<WORMHOLE_PAIRS>(galaxy, WORMHOLE_PAIRS());

    for (int i = 0; i < wormhole; i++)
    {
        int start, end, diff;
        cin >> start >> end >> diff;
        adj[start].push_back(make_pair(make_pair(diff, -diff), end));
    }
    bellman_ford();
}

void bellman_ford()
{
    vector<int> past = vector<int>(galaxy, INF);
    vector<int> future = vector<int>(galaxy, INF);

    past[0] = 0;
    future[0] = 0;

    vector<bool> past_visited = vector<bool>(galaxy, false);
    vector<bool> future_visited = vector<bool>(galaxy, false);

    bool past_update = false;
    bool future_update = false;

    for (int i = 0; i < galaxy; i++)
    {
        for (int j = 0; j < adj.size(); j++)
        {
            int here = j;
            for (int k = 0; k < adj[here].size(); k++)
            {
                PAST_FUTURE_PAIR pair = adj[here][k].first;
                int past_time = pair.first;
                int future_time = pair.second;
                int there = adj[here][k].second;

                if (past[there] > past[here] + past_time)
                {
                    if (i == galaxy - 1 && !past_update && find_vertex(here, 1, past_visited) && find_vertex(0, here, past_visited))
                    {
                        past_update = true;
                    }
                    else
                    {
                        past_visited = vector<bool>(galaxy, false);
                    }

                    past[there] = past[here] + past_time;
                }

                if (future[there] > future[here] + future_time)
                {
                    if (i == galaxy - 1 && !future_update && find_vertex(here, 1, future_visited) && find_vertex(0, here, future_visited))
                    {
                        future_update = true;
                    }
                    else
                    {
                        future_visited = vector<bool>(galaxy, false);
                    }

                    future[there] = future[here] + future_time;
                }
            }
        }
    }

    if (!find_vertex(0, 1, past_visited))
    {
        cout << "UNREACHABLE"
             << "\n";
        return;
    }
    if (past_update)
    {
        cout << "INFINITY"
             << " ";
    }
    else
    {
        cout << past[1] << " ";
    }
    if (future_update)
    {
        cout << "INFINITY"
             << "\n";
    }
    else
    {
        cout << -future[1] << "\n";
    }
}

bool find_vertex(int here, int find, vector<bool> &visited)
{
    visited[here] = true;
    bool ret = false;
    if (visited[find])
    {
        visited = vector<bool>(galaxy, false);
        return true;
    }
    for (int i = 0; i < adj[here].size(); i++)
    {
        if (visited[adj[here][i].second])
            continue;
        ret = find_vertex(adj[here][i].second, find, visited);
        if (ret)
            return ret;
    }
    return ret;
}