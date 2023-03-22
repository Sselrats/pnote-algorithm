#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>
using namespace std;
void buildanswer();
void setanswer(int number, int trial);
void solve();
int numbers[8];
int simp[8];
map<int, int> ans;

struct Pair {
    int number;
    int trial;
};

queue<Pair> q;

int main()
{
    int C;
    cin >> C;
    Pair init = {1234567, 0};
    q.push(init);
    buildanswer();
    while (C--)
    {
        solve();
    }
}

void buildanswer()
{
    while (!q.empty())
    {
        int number = q.front().number;
        int trial = q.front().trial;

        if (ans.count(number) == 0)
        {
            ans[number] = trial;
            for (int i = 1; i <= 7; i++)
            {
                for (int j = i + 1; j <= 8; j++)
                {
                    int reversed = number;
                    int temp = 0;
                    for (int k = i; k <= j; k++)
                    {
                        reversed -= ((number / (int)pow(10, 8 - k)) % 10) * (int)pow(10, 8 - k);
                        temp += ((number / (int)pow(10, 8 - k)) % 10) * (int)pow(10, 8 - (i + j - k));
                    }
                    
                    reversed += temp;
                    Pair _pair = {reversed, trial + 1};
                    q.push(_pair);
                }
            }
        }

        q.pop();
    }
}

void solve()
{
    int N;
    cin >> N;
    for (int i = 0; i < 8; i++)
    {
        simp[i] = i;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
        simp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            if (numbers[i] > numbers[j])
            {
                simp[i]++;
            }
            else
            {
                simp[j]++;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < 8; i++)
    {
        answer = answer * 10 + simp[i];
    }

    cout << ans[answer] << "\n";
}