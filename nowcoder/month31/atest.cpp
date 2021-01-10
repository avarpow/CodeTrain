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
using namespace std;

void solve()
{
    int a, x;
    cin >> a >> x;
    int count = 0;
    for (int i = 1; i <= x; i++)
    {
        if ((a | i) == a + i)
        {
            count++;
        }
    }
    cout << count << endl;
}
void solve2()
{
    long long a, x;
    int d[60] = {0}, e[60] = {0};
    int dp[60] = {0};
    cin >> a >> x;
    int now = 1, cura = 0;
    while (now <= a)
    {
        d[cura++] = ((a & now) != 0 ? 1 : 0);
        now = now * 2;
    }
    now = 1;
    int curb = 0;
    while (now <= x)
    {
        e[curb++] = ((x & now) != 0 ? 1 : 0);
        now = now * 2;
    }
    cout << "a: ";
    for (int i = 0; i < cura; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    cout << "x: ";
    for (int i = 0; i < curb; i++)
    {
        cout << e[i] << " ";
    }
    cout << endl;
    dp[0] = (d[0] == 0 ? 1 : 0);
    for (int i = 1; i < max(cura, curb); i++)
    {
        if (d[i] == 0)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    cout << "dp: ";
    for (int i = 0; i < max(cura, curb); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    long long ans[60] = {0};
    long long lessans[60] = {0};
    for (int i = 0; i < curb; i++)
    {
        if (i == 0)
        {
            if (e[i] == 1)
            {
                if (d[i] == 0)
                {
                    ans[i] = 2;
                }
                else
                {
                    ans[i] = 1;
                }
            }
            else
            {
                ans[i] = 1;
            }
        }
        else
        {
            if (e[i] == 0)
            {
                ans[i] = ans[i - 1];
            }
            else if (d[i] == 1 && e[i] == 1)
            {
                ans[i] = (1 << dp[i - 1]);
            }
            else
            {
                ans[i] = ans[i - 1] + (1 << dp[i - 1]);
            }
        }
    }
    for (int i = 0; i < curb; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl
         << "ans ";
    cout << ans[curb - 1] - 1 << endl;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
        solve2();
    }
    Please AC;
}