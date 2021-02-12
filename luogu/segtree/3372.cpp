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
long long arr[100004] = {0};
long long seg[600006] = {0};
long long tag[600006] = {0};
void build(int node, int x, int y)
{
    tag[node] = 0;
    if (x == y)
    {
        seg[node] = arr[x];
        //mycout << "build x " << x << " y " << y << " val " << seg[node] << endl;
    }
    else
    {
        int mid = (x + y) / 2;
        int left = 2 * node;
        int right = 2 * node + 1;
        build(left, x, mid);
        build(right, mid + 1, y);
        seg[node] = seg[left] + seg[right];
        //mycout << "build x " << x << " y " << y << " val " << seg[node] << endl;
    }
}
void push_down(int node, int x, int y)
{

    int mid = (x + y) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    tag[left] += tag[node];
    tag[right] += tag[node];
    seg[left] += tag[node] * (mid - x + 1);
    seg[right] += tag[node] * (y - mid);
    //cout << "tag[node] " << tag[node] << " x " << x << " y " << y << " seg[node] " << seg[node] << endl;
    tag[node] = 0;
}
ll query(int x, int y, int nowx, int nowy, int node)
{
    ll res = 0;
    int mid = (nowx + nowy) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    if (nowx >= x && nowy <= y)
    {
        //mycout << "query nowx " << nowx << " nowy " << nowy << " val " << seg[node] << endl;
        return seg[node];
    }
    push_down(node, nowx, nowy);
    if (mid >= x)
        res += query(x, y, nowx, mid, left);
    if (mid + 1 <= y)
        res += query(x, y, mid + 1, nowy, right);
    //mycout << "query nowx " << nowx << " nowy " << nowy << " val " << res << endl;
    return res;
}
void update(int x, int y, int nowx, int nowy, int node, int val)
{
    int mid = (nowx + nowy) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    if (nowx >= x && nowy <= y)
    {
        seg[node] += (ll)val * (nowy - nowx + 1);
        tag[node] += val;
        return;
    }
    push_down(node, nowx, nowy);
    if (mid >= x)
        update(x, y, nowx, mid, left, val);
    if (mid + 1 <= y)
        update(x, y, mid + 1, nowy, right, val);
    seg[node] = seg[left] + seg[right];
    //mycout << "update nowx " << nowx << " nowy " << nowy << " seg[node] " << seg[node] << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        int t;
        int x, y, k;
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d%d%d", &x, &y, &k);
            update(x, y, 1, n, 1, k);
        }
        else
        {
            scanf("%d%d", &x, &y);
            ll res = query(x, y, 1, n, 1);
            printf("%lld\n", res);
        }
    }
    Please AC;
}