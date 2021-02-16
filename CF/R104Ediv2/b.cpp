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
    int n, k, flag = 0;
    cin >> n >> k;
    k--;
    if (n % 2 == 0)
    {
        cout << k % n + 1 << endl;
    }
    else
    {
        cout << (k + (k / (n / 2))) % n + 1 << endl;
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