#include <iostream>
#include <string.h>
#include <math.h>
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
    long long x, y;
    cin >> x >> y;
    if (x <= 1)
    {
        cout << -1 << endl;
    }
    else
    {
        long double dx = x, dy = y;
        int k = 0;
        while (pow(x, k) <= y + 0.1)
        {
            k++;
        }
        cout << k - 1 << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
        solve();
    Please AC;
}