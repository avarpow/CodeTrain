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
using namespace std;
string s;
int f[600005];
int ran[600005];
int find(int k)
{
    if (f[k] != k)
    {
        int t = find(f[k]);
        f[k] = t;
    }
    return f[k];
}
void solve()
{
    int n, flag = 0;
    cin >> n;
    for (int i = 0; i <= 2 * (n + 1); i++)
    {
        f[i] = i;
        ran[i] = 1;
    }
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
        {
            int fa = find(i);
            int fb = find((n + 1) + i + 1);
            if (fa != fb)
            {
                ran[fa] += ran[fb];
                ran[fb] = ran[fa];
                f[fb] = f[fa];
                //mycout << "join " << fa << " " << fb << endl;
            }
        }
        if (s[i] == 'L')
        {
            int fa = find(i + 1);
            int fb = find((n + 1) + i);
            if (fa != fb)
            {
                ran[fa] += ran[fb];
                ran[fb] = ran[fa];
                f[fb] = f[fa];
                //mycout << "join " << fa << " " << fb << endl;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", ran[find(i)]);
    }
    printf("\n");
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