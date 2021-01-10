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
bool Issame(string a, string b)
{
    int s[200] = {0};
    for (auto &i : a)
    {
        s[i] = 1;
    }
    for (auto &i : b)
    {
        if (s[i] == 1)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    int n, flag = 0;
    cin >> n;
    string s[200];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int l = 0, r = n - 1;
    for (; l < r; l++, r--)
    {
        if (!Issame(s[l], s[r]))
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;

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