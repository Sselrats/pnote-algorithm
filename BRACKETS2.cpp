#include <iostream>
#include <string>
#include <stack>
using namespace std;
char _pair(char c);
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
    stack<char> st;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (st.empty())
        {
            st.push(c);
        }
        else
        {
            st.top() == _pair(c) && _pair(c) != '0' ? st.pop() : st.push(c);
        }
    }
    string ans = st.empty() ? "YES" : "NO";
    cout << ans << "\n";
}

char _pair(char c)
{
    switch (c)
    {
    case ')':
        return '(';
        break;
    case '}':
        return '{';
        break;
    case ']':
        return '[';
        break;
    default:
        return '0';
        break;
    }
}
