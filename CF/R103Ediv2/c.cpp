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
using namespace std;
long long a[200005];
long long len[200005];
long long b[200005];
long long dp[200005];
long long dp2[200005];
void solve()
{
    int n, flag = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &len[i]);
        len[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        if (a[i] < b[i])
            swap(a[i], b[i]);
    }
    long long maxx = 0;
    dp[n - 1] = len[n - 1] + 2 + a[n - 1] - b[n - 1];
    maxx = max(maxx, dp[n - 1]);
    //mycout << "dp[" << n - 1 << "] " << dp[n - 1] << endl;
    for (int i = n - 2; i > 0; i--)
    {
        if (a[i + 1] == b[i + 1])
        {
            dp[i] = len[i] + a[i] - b[i] + 2;
        }
        else
        {
            dp[i] = max(dp[i + 1] - 2 * (a[i + 1] - b[i + 1]) + len[i] + 2 + a[i] - b[i], len[i] + 2 + a[i] - b[i]);
            maxx = max(maxx, dp[i]);
        }
        //mycout << "dp[" << i << "] " << dp[i] << endl;
        maxx = max(maxx, dp[i]);
    }
    cout << maxx << endl;
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