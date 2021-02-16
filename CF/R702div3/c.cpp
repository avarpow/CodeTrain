#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#define Please return
#define AC 0
#define yn
#define mycout cout
#define ll long long
using namespace std;
map<long long, bool> m;
long long t[100005];
void solve()
{

    long long n, flag = 0;
    cin >> n;
    for (int i = 1; i <= 10000; i++)
    {
        long long ret = n - t[i];
        if (m.find(ret) != m.end())
        {
            flag = 1;
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
    for (long long i = 1; i <= 10000; i++)
    {
        t[i] = i * i * i;
        m[i * i * i] = true;
    }
    while (n--)
        solve();
    Please AC;
}