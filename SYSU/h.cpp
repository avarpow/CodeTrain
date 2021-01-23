#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#define Please return
#define AC 0
// #define yn
using namespace std;
struct edge
{
    long long l, r, w;
};
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
void solve(int cases)
{
    vector<int> a;
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<edge> e;
    map<int, int> vis;
    for (int i = 0; i < n; i++)
    {
        vis[a[i]] = 0;
    }
    e.resize(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        e[i].l = a[i];
        e[i].r = a[i + 1];
        e[i].w = a[i + 1] - a[i];
    }
    sort(e.begin(), e.end(), cmp);
    // for (auto i : e)
    // {
    //     cout << " i.l " << i.l << " i.r " << i.r << " i.w " << i.w << endl;
    // }
    long long maxx = 0, minn = 0;
    for (int i = 0; i < k; i++)
    {
        maxx += a[n - 1 - i] - a[i];
    }
    int now = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (vis[e[i].l] == 0 && vis[e[i].r] == 0)
        {
            // cout << "add "
            //      << " i.l " << e[i].l << " i.r " << e[i].r << endl;
            minn += e[i].w;
            vis[e[i].l] = 1;
            vis[e[i].r] = 1;
            now++;
        }
        if (now == k)
            break;
    }
    printf("Case #%d: %lld %lld\n", cases, minn, maxx);
}
int main()
{
    int n;
    cin >> n;
    int now = 1;
    while (n--)
    {
        solve(now++);
    }
    Please AC;
}