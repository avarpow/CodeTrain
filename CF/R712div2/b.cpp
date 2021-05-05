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
#define N 400005
int a[N] = {0};
int b[N] = {0};
int c[N] = {0};
int check(int r)
{
    return a[r] == 0;
}
void solve()
{
    int n, flag = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char t = getchar();
        while (t != '0' && t != '1')
        {
            t = getchar();
        }
        if (t == '0')
        {
            a[i] = -1;
        }
        else
        {
            a[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        char t = getchar();
        while (t != '0' && t != '1')
        {
            t = getchar();
        }
        if (t == '0')
        {
            b[i] = -1;
        }
        else
        {
            b[i] = 1;
        }
        if (a[i] != b[i])
        {
            c[i] = 1;
        }
        else
        {
            c[i] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i];
    }
    int nowv = 1;
    for (int i = n; i >= 1; i--)
    {
        if (c[i] == nowv)
        {
            if (!check(i))
            {
                flag = 0;
                break;
            }
            nowv = nowv ^ 0 ^ 1;
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