#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
void solve();
int G, H;
int a[1000][1000];
int visited[1000];
void visit(int n);
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
    cin >> G >> H;
    memset(a, 0, sizeof(a));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < H; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for (int i = 0; i < G; i++)
    {
        if (visited[i] == 0)
        {
            visit(i, 1);
        }
    }
}

void visit(int n, int connected_count)
{
    for (int i = 0; i < G;)

}