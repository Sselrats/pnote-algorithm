#include <iostream>
using namespace std;
double prob[50];
double path[50][50];
double temp[50];
void solve();
int main()
{
    int C;
    cin >> C;

    cout << fixed;
    cout.precision(10);

    while (C--)
    {
        solve();
        cout << "\n";
    }
}
void solve()
{
    int n, d, p;
    cin >> n >> d >> p;

    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> path[i][j];
            sum += path[i][j];
        }
        if (i == p)
        {
            prob[i] = 1;
        }
        else
        {
            prob[i] = 0;
        }
        for (int j = 0; j < n; j++)
        {
            path[i][j] = path[i][j] / (double)sum;
        }
    }
    while (d--)
    {
        for (int i = 0; i < n; i++)
        {
            temp[i] = 0;
            for (int j = 0; j < n; j++)
            {
                temp[i] += path[j][i] * prob[j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            prob[i] = temp[i];
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int number;
        cin >> number;
        cout << prob[number] << " ";
    }
}
