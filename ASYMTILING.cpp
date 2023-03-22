#include <iostream>
using namespace std;

void getFibonacci();
int fib[110];
int main()
{
    int C;
    cin >> C;
    getFibonacci();
    while (C--)
    {
        int n;
        cin >> n;
        int ans = (n % 2 == 0 ? fib[n] - fib[n / 2] - fib[n / 2 - 1] : fib[n] - fib[n / 2]);
        while (ans < 0)
        {
            ans += 1000000007;
        }
        cout << ans << "\n";
    }
}

void getFibonacci()
{
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 101; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000007;
    }
}