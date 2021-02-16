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
int a[200005];
int c[200005];
void solve()
{
    int n, flag = 0;
    cin >> n;
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int k = 0;
    int b = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b)
        {
            k++;
        }
        else
        {
            c[k]++;
            k = 1;
            b = a[i];
        }
    }
    c[k]++;

    int minn = 999999999;
    int nowsum = 0;
    for (int i = 200000; i >= 1; i--)
    {
        // if (c[i] != 0)
        // {
        //     cout << "i " << i << " c[i] " << c[i] << " nowsum " << nowsum << endl;
        // }
        if (n - c[i] * i < minn)
        {
            minn = n - c[i] * i;
        }
        nowsum += c[i];
        c[i - 1] += c[i];
    }
    cout << minn << endl;
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