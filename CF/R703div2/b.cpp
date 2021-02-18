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
int x[2000];
int y[2000];
void solve()
{

    int n, flag = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        cin >> y[i];
    }
    sort(x, x + n);
    sort(y, y + n);
    if (n % 2 == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << ((long long)x[n / 2] - x[n / 2 - 1] + 1) * ((long long)y[n / 2] - y[n / 2 - 1] + 1) << endl;
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
    int n;
    cin >> n;
    while (n--)
        solve();
    Please AC;
}