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
#define mycerr cout
// #define yn
using namespace std;
int a[200005];
int divmin[2005];
int divsum[2005];
int divmax[2005];
int sum[200005];
int premax[200005];
int premin[200005];
void solve()
{
    int n, m, flag = 0;
    cin >> n;
    cin >> m;
    memset(divmax, 0x8f, sizeof(divmax));
    memset(premax, 0x8f, sizeof(premax));
    for (int i = 0; i < 2005; i++)
    {
        divmin[i] = 999999999;
    }
    for (int i = 0; i <= n; i++)
    {
        premin[i] = 999999999;
    }
    for (int i = 1; i <= n; i++)
    {
        char t;
        cin >> t;
        if (t != '+' && t != '-')
        {
            cin >> t;
        }
        if (t != '+' && t != '-')
        {
            cin >> t;
        }
        if (t == '+')
        {
            a[i] = 1;
        }
        else if (t == '-')
        {
            a[i] = -1;
        }
    }
    sum[0] = 0;
    premax[0] = 0;
    premin[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        premax[i] = max(premax[i - 1], sum[i]);
        premin[i] = min(premin[i - 1], sum[i]);
    }
    // if (n == 200000)
    // {
    //     mycerr << "premax[n] " << premax[n] << " sum[n] " << sum[n] << " premin[n] " << premin[n] << endl;
    // }

    for (int i = 1; i + 999 <= n; i += 1000)
    {
        int ranmin = 0, ranmax = 0, ransum = 0;
        for (int j = 0; j < 1000; j++)
        {
            ransum += a[i + j];
            ranmax = max(ranmax, ransum);
            ranmin = min(ranmin, ransum);
        }
        divmin[i / 1000] = ranmin;
        divmax[i / 1000] = ranmax;
        divsum[i / 1000] = ransum;
        //if (n == 200000)
        //mycerr << "block i " << i / 1000 << " ransum " << ransum << " ranmax " << ranmax << " ranmin " << ranmin << endl;
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        // if (n == 200000)
        //     mycerr << "check " << l << " " << r << endl;
        int ansmin = premin[l - 1], ansmax = premax[l - 1], anssum = sum[l - 1];
        int j;
        // if (n == 200000)

        //     mycerr << "pre ansmin " << ansmin << " ansmax " << ansmax << " anssum " << anssum << endl;
        for (j = r + 1; j % 1000 != 1 && j <= n; j++)
        {
            anssum += a[j];
            ansmax = max(ansmax, anssum);
            ansmin = min(ansmin, anssum);
        }
        // if (n == 200000)

        //     mycerr << "pre j " << j << " ";
        // if (n == 200000)

        //     mycerr << "prediv ansmin " << ansmin << " ansmax " << ansmax << " anssum " << anssum << endl;

        for (; j + 999 <= n; j += 1000)
        {
            // if (n == 200000)

            //     mycerr << " j " << j << " ";
            ansmax = max(ansmax, anssum + divmax[j / 1000]);
            ansmin = min(ansmin, anssum + divmin[j / 1000]);
            anssum += divsum[j / 1000];
            // if (n == 200000)
            //     mycerr << "div ansmin " << ansmin << " ansmax " << ansmax << " anssum " << anssum << endl;
        }
        for (; j <= n; j++)
        {
            anssum += a[j];
            ansmax = max(ansmax, anssum);
            ansmin = min(ansmin, anssum);
        }
        // if (n == 200000)
        //     mycerr << "enddiv ansmin " << ansmin << " ansmax " << ansmax << " anssum " << anssum << endl;
        cout << ansmax - ansmin + 1 << endl;
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
    //freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    while (n--)
        solve();
    Please AC;
}