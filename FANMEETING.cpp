#include <iostream>
#include <vector>
using namespace std;
void solve();
vector<int> karatsuba(const vector<int> &a, const vector<int> &b);
vector<int> mul(const vector<int> &a, const vector<int> &b);
void addk(vector<int> &a, const vector<int> &b, int k);
void sub(vector<int> &a, const vector<int> &b);

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
    string member, fan;
    cin >> member;
    cin >> fan;

    int m = member.length();
    int f = fan.length();

    vector<int> M(m), F(f);

    for (int i = 0; i < m; i++)
    {
        M[i] = (member[i] == 'M');
    }
    for (int i = 0; i < f; i++)
    {
        F[i] = (fan[f - 1 - i] == 'M');
    }

    vector<int> C = karatsuba(M, F);

    int ans = 0;
    for (int i = m - 1; i < f; i++)
    {
        if (C[i] == 0)
        {
            ans++;
        }
    }
    cout << ans << "\n";
}

vector<int> karatsuba(const vector<int> &a, const vector<int> &b)
{
    int l_a = a.size(), l_b = b.size();

    if (l_a < l_b)
        return karatsuba(b, a);

    if (l_a == 0 or l_b == 0)
        return vector<int>();

    if (l_a < 100)
        return mul(a, b);

    int half = l_a / 2;

    // a = a1 * 10 ^ half + a0;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());

    // b = b1 * 10 ^ half + b0;
    vector<int> b0(b.begin(), b.begin() + min(half, (int)b.size()));
    vector<int> b1(b.begin() + min(half, (int)b.size()), b.end());

    /*
    a * b = "a1 * b1" * 10^(2half)
          + "(a1 + a0) * (b1 + b0) - (a1 * b1) - (a0 * b0)"* 10 ^ half
          + "a0 * b0"
    */

    vector<int> c2 = karatsuba(a1, b1);
    vector<int> c0 = karatsuba(a0, b0);
    addk(a1, a0, 0);
    addk(b1, b0, 0);
    vector<int> c1 = karatsuba(a1, b1);
    sub(c1, c0);

    addk(c1, c2, half);
    addk(c0, c1, half);
    return c0;
}

vector<int> mul(const vector<int> &a, const vector<int> &b)
{
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += (a[i] * b[j]);
    return c;
}

void addk(vector<int> &a, const vector<int> &b, int k)
{
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); i++)
        a[i + k] += b[i];
}

void sub(vector<int> &a, const vector<int> &b)
{
    a.resize(max(a.size(), b.size()) + 1);
    for (int i = 0; i < b.size(); i++)
        a[i] -= b[i];
}