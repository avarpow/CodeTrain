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
#define yn
#define mycout cout
#define ll long long
using namespace std;

void solve()
{
    long long n, flag = 1;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        if (t < i)
        {
            if (t + sum < i)
            {
                flag = 0;
            }
            else
            {
                sum -= i - t;
            }
        }
        else
        {
            sum += t - i;
        }
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