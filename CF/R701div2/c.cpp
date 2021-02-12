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
    int x, y;
    cin >> x >> y;
    long long ans = 0;
    int k = 1;
    while (y - k > 0 && x / k - k - 1 > 0)
    {
        ans += min(y - k, x / k - k - 1);
        k++;
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