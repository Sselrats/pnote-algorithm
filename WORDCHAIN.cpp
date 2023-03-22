#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int considered[26];
vector<int> answerline;
vector<string> ans;
map< pair<char, char>, vector<string> > dict;
void DFS(int n);
bool result();
void solve();
int char_to_num(char c);
char num_to_char(int n);
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
    answerline.clear();
    ans.clear();
    dict.clear();
    memset(considered, 0, sizeof(considered));

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        considered[char_to_num(word.front())]++;
        pair<char, char> p = make_pair(word.front(), word.back());

        if (dict.find(p) == dict.end())
        {
            dict[p] = vector<string>();
        }
        dict[p].push_back(word);
    }

    for (int i = 0 ; i < 26; i++)
    {
        DFS(i);
    }

    if (answerline.size() != N)
    {
        cout << "IMPOSSIBLE" << "\n";
        return;
    }
    
	reverse(answerline.begin(), answerline.end());

    char leftover = num_to_char(answerline[N - 1]);

    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            for (int j = 0; j < 26; j++)
            {
                pair<char, char> _p = make_pair(leftover, num_to_char(j));
                if (dict.find(_p) != dict.end())
                {
                    ans.push_back(dict[_p].back());
                    break;
                }
            }
        }
        else
        {
            pair<char, char> _p = make_pair(num_to_char(answerline[i]), num_to_char(answerline[i + 1]));
            if (dict.find(_p) == dict.end())
            {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
            ans.push_back(dict[_p].back());
            dict[_p].pop_back();
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
    	cout << ans[i] << " ";
    }
    cout << "\n";
}

void DFS(int n)
{
    if (considered[n] == 0) return;

    considered[n]--;
    for (int i = 0; i < 26; i++)
    {
        if (dict.find(make_pair(num_to_char(n), num_to_char(i))) != dict.end()
         && considered[i] != 0)
        {
            DFS(i);
        }
    }
    answerline.push_back(n);
}

int char_to_num(char c)
{
    return c - 'a';
}

char num_to_char(int n)
{
    return 'a' + n;
}
