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
    int op[7] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        op[t + 3]++;
    }
    int min3 = min(op[0], op[6]);
    int min2 = min(op[1], op[5]);
    int min1 = min(op[2], op[4]);
    op[0] -= min3;
    op[1] -= min2;
    op[2] -= min1;
    op[4] -= min1;
    op[5] -= min2;
    op[6] -= min3;
    //-1 -2 +3
    int min4 = min(op[1], min(op[2], op[6]));
    int min5 = min(op[4], min(op[5], op[0]));
    op[1] -= min4;
    op[2] -= min4;
    op[6] -= min4;
    op[4] -= min5;
    op[5] -= min5;
    op[0] -= min5;

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