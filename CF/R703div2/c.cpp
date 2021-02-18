//unac
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
int *a = NULL;
int b;
void dfs(int l, int r, int step)
{
    if (l > r)
        b = *a;
    if (l == r)
    {
        cout << "! " << l << endl;
        cout.flush();
        return;
    }
    else
    {
        cout << "? " << l << " " << r << endl;
        cout.flush();
        int t;
        cin >> t;
        if (t == l)
        {
            dfs(t + 1, r, step + 1);
        }
        else if (t == r)
        {
            dfs(l, t - 1, step + 1);
        }
        else
        {
            cout << "? " << t << " " << r << endl;
            cout.flush();
            int k;
            cin >> k;
            if (k == t)
            {
                dfs(t + 1, r, step + 1);
            }
            else
            {
                dfs(l, t - 1, step + 1);
            }
        }
    }
}
void solve()
{
    int n, flag = 0;
    cin >> n;
    int l = 1, r = n;
    dfs(l, r, 0);
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
    solve();
    Please AC;
}