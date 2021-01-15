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
    int n, k, flag = 0;
    cin >> n >> k;
    int t = n - k;
    int now = 1;
    for (int i = 0; i < k - t - 1; i++)
    {
        cout << now++ << " ";
    }
    now = k;
    for (int i = 0; i < t + 1; i++)
    {
        cout << now-- << " ";
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