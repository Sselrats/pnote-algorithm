#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverse(string::iterator &it)
{
    char first = *it;
    string quad[5];
    ++it;
    if (first != 'x')
    {
        return string(1, first);
    }
    else
    {
        for (int i = 1; i < 5; i++)
        {
            quad[i] = reverse(it);
        }
    }
    return "x" + quad[3] + quad[4] + quad[1] + quad[2];
}

void solve()
{
    string str;
    cin >> str;
    string::iterator it = str.begin();
    str = reverse(it);
    cout << str << "\n";
}

int main()
{
    int C;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        solve();
    }
}