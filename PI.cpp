#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
void solve();
int ans(string input, int index);
int chkans[10000];
int diff(int input, int length);
int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        memset(chkans, -1, sizeof(chkans));
        solve();
    }
}
void solve()
{
    string input;
    cin >> input;
    cout << ans(input, 0) << "\n";
}
int ans(string input, int index)
{
    if (chkans[index] != -1) return chkans[index];
    int answer = 100000;
    if (index == input.length()) return chkans[index] = 0;
    if (input.length() - index < 3|| index > input.length()) return chkans[index] = answer;
    int input3 = (int)input[index] * 100 + (int)input[index + 1] * 10 + (int)input[index + 2] - 5328;
    int input4 = input3 * 10 + (int)input[index + 3] - 48;
    int input5 = input4 * 10 + (int)input[index + 4] - 48;

    answer = min(answer, ans(input, index + 3) + diff(input3, 3));
    answer = min(answer, ans(input, index + 4) + diff(input4, 4));
    answer = min(answer, ans(input, index + 5) + diff(input5, 5));
    return chkans[index] = answer;
}
int diff(int input, int length)
{
    int e = input % 10;
    int d = (input % 100) / 10;
    int c = (input % 1000) / 100;
    int b = (input % 10000) / 1000;
    int a = (input / 10000);

    if (length == 3)
    {
        if (input % 111 == 0) return 1;
        if (((input - 12) % 111 == 0 && input / 100 < 8) || ((input - 210) % 111 == 0 && input / 100 > 1)) return 2;
        if (c == e) return 4;
        if (c + e == 2 * d) return 5;
    }
    if (length == 4)
    {
        if (input % 1111 == 0) return 1;
        if (((input - 123) % 1111 == 0 && input / 1000 < 7) || ((input - 3210) % 1111 == 0 && input / 1000 > 2)) return 2;
        if (c == e && b == d) return 4;
        if (b + d == 2 * c && c + e == 2 * d) return 5;
    }
    if (length == 5)
    {
        if (input % 11111 == 0) return 1;
        if (((input - 1234) % 11111 == 0 && input / 10000 < 6) || ((input - 43210) % 11111 == 0&& input / 10000 > 3)) return 2;
        if (a == c && c == e && b == d) return 4;
        if (b + d == 2 * c && c + e == 2 * d && a + c == 2 * b) return 5;
    }
    return 10;
}