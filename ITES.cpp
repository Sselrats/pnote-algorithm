#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
void generatequeue(int n);
queue<long> q;
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
    int k, n;
    cin >> k >> n;

    queue<long> empty;
    swap(q, empty);

    q.push(1983);
    long insert = 1983;

    long ans = 0;
    for (int i = 0; i < n;)
    {
        long sum = q.back() - q.front();
        if (sum < k)
        {
            insert = ((insert * 214013 + 2531011) % (long)pow(2, 32));
            q.push(q.back() + insert % 10000 + 1);
            i++;
        }
        else if (sum > k)
        {
            q.pop();
        }
        else
        {
            ans++;
            q.pop();
        }
    }
    cout << ans << "\n";
}