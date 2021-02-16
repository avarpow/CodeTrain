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
int a[1000];
void solve()
{
    int n, flag = 0;
    cin >> n;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int maxx = max(a[i], a[i + 1]);
        int minn = min(a[i], a[i + 1]);
        int k = 0;
        while (minn * 2 < maxx)
        {
            minn *= 2;
            k++;
        }
        ret += k;
    }
    cout << ret << endl;

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