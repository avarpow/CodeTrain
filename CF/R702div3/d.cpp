#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#define Please return
#define AC 0
// #define yn
#define mycout cout
#define ll long long
using namespace std;
int dep[200];
int a[200];
void dfs(int l, int r, int depth)
{
    int maxx, maxi;
    if (l > r)
        return;
    if (l == r)
    {
        maxi = l;
        maxx = a[l];
        dep[maxi] = depth;
        //cout << "find maxx " << maxx << " maxi " << maxi << " at depth " << depth << endl;
    }
    else
    {
        maxx = a[l];
        maxi = l;
        for (int i = l; i <= r; i++)
        {
            if (a[i] > maxx)
            {
                maxx = a[i];
                maxi = i;
            }
        }
        //cout << "find maxx " << maxx << " maxi " << maxi << " at depth " << depth << endl;
        dep[maxi] = depth;
        dfs(l, maxi - 1, depth + 1);
        dfs(maxi + 1, r, depth + 1);
    }
}
void solve()
{
    int n, flag = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs(0, n - 1, 0);
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", dep[i], i == n - 1 ? "\n" : " ");
    }
#ifdef yn
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
#endif
}
int main()
{
    int n;
    cin >> n;
    while (n--)
        solve();
    Please AC;
}