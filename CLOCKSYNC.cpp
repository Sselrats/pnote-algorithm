#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#define inf 100000000
using namespace std;

int cnt = 0;
int cl[16];
int button[10][6] = {
    {0, 1, 2, -1},
    {3, 7, 9, 11, -1},
    {4, 10, 14, 15, -1},
    {0, 4, 5, 6, 7, -1},
    {6, 7, 8, 10, 12, -1},
    {0, 2, 14, 15, -1},
    {3, 14, 15, -1},
    {4, 5, 7, 14, 15, -1},
    {1, 2, 3, 4, 5, -1},
    {3, 4, 5, 9, 13, -1}};

void click(int c)
{
    for (int i = 0; button[c][i] != -1; i++)
        cl[button[c][i]] = (cl[button[c][i]] + 3) % 12;
    cnt++;
}
void solve()
{
    for (int i = 0; i < 16; i++)
    {
        scanf("%d", &cl[i]);
        cl[i] = (cl[i] == 12 ? 0 : cl[i]);
    }
    cnt = 0;
    if (cl[8] != cl[12])
    {
        cout << "-1"
             << "\n";
        return;
    }
    while (cl[8] != 0)
        click(4);
    while (cl[11] != 0)
        click(1);
    while (cl[13] != 0)
        click(9);
    if (cl[9] != 0)
    {
        cout << "-1"
             << "\n";
        return;
    }
    while (cl[6] != 0)
        click(3);
    while (cl[10] != 0)
        click(2);
    while (cl[7] != 0)
        click(7);
    while (cl[5] != 0)
        click(8);
    while (cl[4] != 0)
        click(9);
    while (cl[1] != 0)
        click(0);
    if (cl[0] != cl[2])
    {
        cout << "-1"
             << "\n";
        return;
    }
    while (cl[0] != 0)
        click(5);
    if (cl[3] != cl[14] && cl[14] != cl[15])
    {
        cout << "-1"
             << "\n";
        return;
    }
    while (cl[14] != 0)
        click(6);

    cout << cnt << "\n";
}

int main()
{
    int C;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        solve();
    }
}