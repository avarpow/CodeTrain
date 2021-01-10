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
    int n, flag = 0;
    string s;
    cin >> s;
    int k[200] = {0};
    for (auto &i : s)
    {
        k[i] = 1;
    }
    int c = 0;
    for (int i = 0; i < 200; i++)
    {
        if (k[i] == 1)
            c++;
    }
    if (c == 1)
    {
        cout << 0 << endl;
        return;
    }
    flag = 0;
    int l, r;
    for (l = 0, r = s.size() - 1; l < r; l++, r--)
    {
        if (s[l] != s[r])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << s.size() << endl;
    }
    else
    {
        cout << s.size() - 1 << endl;
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
    // cin >> n;
    // while (n--)
    solve();
    Please AC;
}