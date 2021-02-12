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
#define mycout cout << "out:"
#define ll long long
using namespace std;
int a[200005];
int c[200005];
int sum[200005] = {0};
void solve()
{
    int n, q, k;
    scanf("%d%d%d", &n, &q, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        c[i] = a[i + 1] - a[i - 1] - 2;
    }
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + c[i];
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        long long ans = 0;
        if (l == r)
        {
            ans = k - 1;
        }
        else
        {
            ans += (a[l + 1] - 2);
            //mycout << ans << endl;
            ans += (k - a[r - 1] - 1);
            //mycout << ans << endl;
            ans += (sum[r - 1] - sum[l]);
            //mycout << ans << endl;
        }
        printf("%lld\n", ans);
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
    // int n;
    // cin >> n;
    // while (n--)
    solve();
    Please AC;
}