//false
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
    int n, flag = 0;
    cin >> n;
    int rest = n % 6;
    int ci = n / 6;
    if (rest == 0)
    {
        cout << ci * 3 << endl;
    }
    else if (rest == 1)
    {
        cout << ci * 3 + 1 << endl;
    }
    else if (rest == 3)
    {
        cout << ci * 3 + 2 << endl;
    }
    else
    {
        cout << "Impossible" << endl;
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