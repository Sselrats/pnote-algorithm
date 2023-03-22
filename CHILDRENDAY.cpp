#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <map>
using namespace std;
void solve();
set<int> parse(string str);
map< int, set<int> > connected;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}

void solve()
{
    connected.clear();

    string _str;
    int N, M;

    cin >> _str >> N >> M;

    set<int> valid = parse(_str);
    set<int>::iterator it;

    bool invalid = true;

    for (int i = 0; i < 2 * N; i++)
    {
        set<int> blank;
        connected[i] = blank;

        set<int>::iterator it;
        for (it = valid.begin(); it != valid.end(); ++it)
        {
            int _next = (i * 10 + *it);
            connected[i].insert( _next < N ? _next : _next % N + N);
            if (_next % N + N == M + N)
            {
                invalid = false;
            }
        }
    }

    if (invalid)
    {
        cout << "IMPOSSIBLE" << "\n";
        return;
    }

    queue<long long> q;

    for (it = valid.begin(); it != valid.end(); ++it)
    {
        q.push(*it);
    }

    for (int i = 0; i < 10; i++)
    {
        long long front = q.front();
        if (front % N == M && front > N)
        {
            cout << front << "\n";
            return;
        }
        for (it = valid.begin(); it != valid.end(); ++it)
        {
            q.push(front * 10 + *it);
        }
    }

    cout << 1234 << "\n";
    return;
}

set<int> parse(string str)
{
    set<int> s;
    for (int i = 0; i < str.size(); i++)
    {
        s.insert(str[i] - '0');
    }

    return s;
}