#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
void post(const vector<int> &p, const vector<int> &q);
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
    int N;
    cin >> N;
    vector<int> p, q;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        p.push_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        q.push_back(a);
    }
    post(p, q);
}
void post(const vector<int> &p, const vector<int> &q)
{
    int N = p.size();
    if (p.empty())
    {
        return;
    }
    int root = p[0];
    int left_length = find(q.begin(), q.end(), root) - q.begin();

    post(vector<int>(p.begin() + 1, p.begin() + left_length + 1),
         vector<int>(q.begin() + 0, q.begin() + left_length));
    post(vector<int>(p.begin() + left_length + 1, p.begin() + N),
         vector<int>(q.begin() + left_length + 1, q.begin() + N));
    cout << root << " ";
}