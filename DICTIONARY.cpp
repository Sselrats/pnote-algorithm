#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int arr[26][26];
int considered[26];
string words[1001];
vector<char> ans;
void solve();
void DFS(int n);
bool result();
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
    memset(arr, 0, sizeof(arr));
    memset(considered, 0, sizeof(considered));
    ans.clear();
    
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        words[i] = word;
        if (i != 0)
        {
            string pre_word = words[i - 1];
            for (string::size_type index = 0; index < pre_word.size() && index < word.size(); index++)
            {
                int pre_char_to_num = char_to_num(pre_word[index]);
                int now_char_to_num = char_to_num(word[index]);

                if (pre_char_to_num != now_char_to_num)
                {
                    arr[pre_char_to_num][now_char_to_num] = 1;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (considered[i] == 0) DFS(i);
    }

    if (!result())
    {
        cout << "INVALID HYPOTHESIS\n";
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            cout << num_to_char(ans[i]);
        }
        cout << "\n";
    }
}

void DFS(int n)
{
    considered[n] = 1;
    for (int i = 0; i < 26; i++)
    {
        if (arr[n][i] == 1 && considered[i] == 0)
        {
            DFS(i);
        }
    }
    ans.push_back(n);
}

bool result()
{
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < 26; i++)
    {
		for (int j = i + 1; j < 26; j++)
        {
			if (arr[ans[j]][ans[i]] == 1)
				return false;
		}
	}
	return true;
}

int char_to_num(char c)
{
    return c - 'a';
}

char num_to_char(int n)
{
    return 'a' + n;
}
