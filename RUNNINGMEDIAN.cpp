#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std; 
int C, N, a, b;
int mod = 20090711;
void solve();
int main()
{
	cin >> C;
	while (C--) {
    solve();
	}
}
void solve()
{
	cin >> N >> a >> b;

	int ans = 0;
	long long value = 1983;

	priority_queue< int, vector<int>, less<int> > maxHeap;
	priority_queue< int, vector<int>, greater<int> > minHeap;

	for (int i = 0; i < N; i++) {
		if (maxHeap.size() == minHeap.size())
    {
			maxHeap.push(value);
    }
		else
    {
			minHeap.push(value);
    }
		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int minor = maxHeap.top(), major = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(major);
			minHeap.push(minor);
		}
		ans = (ans + maxHeap.top()) % mod;
		value = (value * a + b) % mod;
	}


		cout << ans << "\n";
}
// void solve()
// {
// 	cin >> N >> a >> b;
// 	int ans = 0;
// 	long long value = 1983;
// 	set<int> set;
// 	for (int i = 0; i < N; i++)
// 	{
// 		set.insert(value);
// 		ans = (ans + *std::next(set.begin(), (set.size() - 1) / 2)) % mod;
// 		value = (value * a + b) % mod;
// 	}
// 	cout << ans <<  "\n";
// }