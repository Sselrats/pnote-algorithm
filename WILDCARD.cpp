#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> ans;
string W;
string S;

bool compare(string a, string b) { return a < b; }
void solve();
bool check(int w, int s);
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
    cin >> W;
    int N;
    cin >> N;
    while (N--)
    {
        cin >> S;
        if (check(0, 0))
        {
            ans.push_back(S);
        }
    }
    sort(ans.begin(), ans.end(), compare);
    for (vector<string>::iterator it = ans.begin(); it < ans.end(); ++it)
    {
        cout << *it << "\n";
    }
    ans.clear();
}
bool check(int w, int s)
{
    while (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
    {
        w++;
        s++;
    }
    if (w == W.size())
    {
        return s == S.size();
    }
    if (W[w] == '*')
    {
        for (int i = 0; s + i <= S.size(); i++)
        {
            if (check(w + 1, s + i))
            {
                return true;
            }
        }
    }
    return false;
}
