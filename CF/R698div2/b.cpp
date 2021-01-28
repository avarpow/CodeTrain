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
    int q, d, flag = 0;
    cin >> q >> d;
    vector<int> t;
    t.push_back(d);
    for (int i = 1; i < 20; i++)
    {
        t.push_back(i * d);
    }
    for (int i = 10; i < 100; i += 10)
    {
        t.push_back(i + d);
        int tem = t.size();
        for (int j = 0; j < tem; j++)
        {
            t.push_back(t[j] + i + d);
        }
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (int i = 0; i < 10; i++)
    {
        t.push_back(10 * d + i);
        int tem = t.size();
        for (int j = 0; j < tem; j++)
        {
            t.push_back(t[j] + 10 * d + i);
        }
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    // for (auto i : t)
    // {
    //     cout << i << " ";
    // }
    //cout << endl;
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        int flag = 0;
        if (k > d * (10 + d))
        {
            flag = 1;
        }
        else
        {
            for (auto &i : t)
            {
                if (i == k)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
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