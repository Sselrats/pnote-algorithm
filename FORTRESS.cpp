#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve();
int x[1100], y[1100], r[1100];
int main()
{
    int C;
    cin >> C;
    solve();
}
void solve()
{
    int N;
    cin >> N;
    vector<int> v[N];
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (circle(i, j) == 1)
            {
                v[i].push_back(j);
            }
            if (circle(i, j) == -1)
            {
                v[j].push_back(i);
            }
        }
    }

    vector<int> depth[v[1].size()];
}

int circle(int i, int j)
{
    int distdist = x[i] * x[i] + y[i] * y[i];
    if (distdist < r[i] * r[i] || distdist < r[j] * r[j])
    {
        if (r[i] > r[j])
        {
            return 1;
        }
        if (r[i] < r[j])
        {
            return -1;
        }
    }
    else
    {
        return 0;
    }
}