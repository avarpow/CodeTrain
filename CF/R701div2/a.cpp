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
void solve()
{
    long long a, b;
    cin >> a >> b;
    int ans = 0;
    int flag = 0;
    if (a == b)
    {
        cout << 2 << endl;
        return;
    }
    else
    {
        ans = 999999999;
        int p;
        if (b == 1)
        {
            b = 2;
            flag = 1;
        }
        long long t = b;
        long long c = 1;
        long long c2 = 1;
        int k = 1;
        do
        {
            t = b;
            c = 1, c2 = 1;
            while (t <= a)
            {
                t *= b;
                c++;
            }
            t = b + 1;
            while (t <= a)
            {
                t *= (b + 1);
                c2++;
            }
            int m = min(c + k - 1, c2 + k);
            ans = min(ans, m);
            b = b + 1;
            k++;
        } while (c2 + k <= c + k - 1);
    }
    cout << ans + flag << endl;

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