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
long long a[1000];
long long sum[1000];
long long req[1000];
void solve()
{
    int n, k, flag = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {
            sum[i] = a[i];
        }
        else
        {
            sum[i] = sum[i - 1] + a[i];
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        if ((a[i] * 100) % k == 0)
        {
            req[i - 1] = a[i] * 100 / k;
        }
        else
        {
            req[i - 1] = a[i] * 100 / k + 1;
        }
    }
    long long maxx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        //mycout << req[i] << " " << sum[i] << endl;
        maxx = max(maxx, req[i] - sum[i]);
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