#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <math.h>
#include <algorithm>
#define Please return
#define AC 0
// #define yn
using namespace std;
void solve()
{
    int n, flag = 0;
    cin >> n;

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
    double maxx = 0;
    for (int i = 0; i <= n; i++)
    {
        double now = (200 * i + 100 * (n - i)) * pow(1.1, (n - i));
        maxx = max(maxx, now);
    }
    printf("%.9llf", maxx);
    Please AC;
}