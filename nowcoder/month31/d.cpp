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
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (c - a + 1) * (d - b + 1) << endl;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
        solve();
    Please AC;
}