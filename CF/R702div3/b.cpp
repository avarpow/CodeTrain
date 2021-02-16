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
int a[30040];
void solve()
{
    int n, flag = 0;
    cin >> n;
    int c[6] = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i] % 3]++;
        c[a[i] % 3 + 3]++;
    }
    int k = n / 3;
    for (int i = 0; i < 6; i++)
    {
        c[i] -= k;
    }
    int ret = 0;
    for (int i = 3; i < 6; i++)
    {
        // for (int j = 0; j < 6; j++)
        // {
        //     cout << c[j] << " ";
        // }
        // cout << endl;
        if (c[i] < 0)
        {
            // cout << "c[i]<0" << endl;
            ret += abs(c[i]);
            c[i - 1] += c[i];
            c[i + 2] += c[i];
            c[i] = 0;
            c[i + 3] = 0;
            // for (int j = 0; j < 6; j++)
            // {
            //     cout << c[j] << " ";
            // }
            // cout << endl;
            if (c[i - 1] < 0)
            {
                // cout << "c[i-1]<0" << endl;
                ret += abs(c[i - 1]);
                c[i - 2] += c[i];
                c[i + 1] += c[i];
                c[i - 1] = 0;
                c[i + 2] = 0;
                // for (int j = 0; j < 6; j++)
                // {
                //     cout << c[j] << " ";
                // }
                // cout << endl;
            }
        }
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