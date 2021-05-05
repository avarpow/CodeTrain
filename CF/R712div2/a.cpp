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
    int n, flag = 0;
    string s;
    cin >> s;
    for (auto i : s)
    {
        if (i != 'a')
            flag = 1;
    }
    if (flag == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        int t = 0, k;
        for (k = s.size() - 1; s[k] == 'a'; k--, t++)
            ;
        cout << "YES" << endl;
        for (int i = 0; i < t; i++)
        {
            cout << s[i];
        }
        cout << 'a';
        for (int i = t; i < s.size(); i++)
        {
            cout << s[i];
        }
        cout << endl;
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