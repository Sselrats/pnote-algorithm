#include <iostream>
#include <algorithm>
using namespace std;
int a[20001];
void solve();
int rec(int left, int right);
pair<int, int> minimum(int left, int right);
int main()
{
    int C;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        solve();
    }
}

void solve()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    cout << rec(0, N - 1) << "\n";
}

int rec(int left, int right)
{
    if (left > right)
    {
        return 0;
    }
    if (left == right)
    {
        return a[left];
    }
    pair<int, int> min = minimum(left, right);
    int ans = min.second * (right - left + 1);

    int temp = max(rec(left, min.first - 1), rec(min.first + 1, right));

    return max(ans, temp);
}

pair<int, int> minimum(int left, int right)
{
    int first = right, second = a[right];
    for (int i = left; i < right; i++)
    {
        if (a[i] < second)
        {
            first = i;
            second = a[i];
        }
    }
    return pair<int, int>(first, second);
}