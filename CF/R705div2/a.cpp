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
#define uio cout
#define ll long long
using namespace std;
void solve()
{
    int n, k, flag = 0;
    cin >> n >> k;
    if (k % 2 == 0)
    {
        flag = 1;
    }
    cout << k - 2 - k / 2 + 1 + n - k + flag << endl;
    if (flag)
        cout << k / 2 << " ";
    for (int i = k / 2 + 1; i < k; i++)
    {
        cout << i << " ";
    }
    for (int i = k + 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;

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