#include <iostream>
#include <set>
using namespace std;
void solve();
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
    int n, k;
    cin >> n >> k;
    set<int> set;
    int killindex = 0;
    for (int i = 1; i <= n; i++)
    {
        set.insert(i);
    }
    while (set.size() != 2)
    {
        int kill = *std::next(set.begin(), killindex);
        set.erase(kill);
        killindex += k - 1 + set.size();
        killindex %= set.size();
    }
    for (auto iter = set.begin(); iter != set.end(); iter++)
    {
        cout << *iter << " ";
    }
}
