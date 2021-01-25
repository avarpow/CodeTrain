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
#define MOD 1000000007
using namespace std;
long long qpow(long long now, int pow)
{
    long long ans = 1;
    //cout << "now " << now << "pow " << pow << endl;
    while (pow >= 1)
    {
        if (pow & 1)
        {
            ans = ans * now % MOD;
            //cout << "ans " << ans << endl;
        }
        //cout << "nwo " << now << endl;
        now = now * now % MOD;
        pow = pow >> 1;
    }
    //cout << "ans " << ans << endl;
    return ans;
}
long long save[1005];
long long inv(int a)
{
    if (save[a] == -1)
    {
        save[a] = qpow(a, MOD - 2) % MOD;
        //cout << " a" << save[a];
    }
    return save[a];
}
void solve()
{
    memset(save, -1, sizeof(save));
    int n, m;
    int tong[1005] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        tong[t]++;
    }
    long long ans = 1;
    for (int i = 1000; i >= 0; i--)
    {
        if (tong[i] > 0 && m > 0)
        {
            if (m >= tong[i])
            {
                m -= tong[i];
            }
            else
            {
                //cout << tong[i] << " m " << m << endl;
                for (int j = tong[i]; j >= tong[i] - m + 1; j--)
                {
                    ans = ans * j % MOD;
                    //cout << "j " << j << " ans " << ans << endl;
                }
                for (int j = 2; j <= m; j++)
                {
                    ans = ans * inv(j) % MOD;
                    //cout << "inv j " << j << " ans " << ans << endl;
                }
                m = 0;
            }
        }
    }
    cout << ans << endl;

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