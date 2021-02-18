#include <iostream>
#include <string.h>
//unac
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
multiset<int, greater<int>> small;
multiset<int> big;
int a[200005];
void solve()
{
    int n, k, flag = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int l = 0, r = 0;
    int maxx = 0;
    while (r < n)
    {
        if (small.empty() || a[r] >= *small.begin())
        {
            int k = a[r++];
            if (k <= *small.begin())
            {
                small.insert(k);
                if (small.size() - big.size() > 1)
                {
                    big.insert(*small.begin());
                    small.erase(small.begin());
                }
            }
            else
            {
                big.insert(k);
                if (small.size() < big.size())
                {
                    small.insert(*big.begin());
                    big.erase(big.begin());
                }
            }
            if (r - l >= k)
            {
                maxx = max(maxx, *small.begin());
            }
        }
        else
        {
            int k = a[l++];
            if (k <= *small.begin())
            {
                auto iter = small.find(k);
                small.erase(iter);
                if (small.size() < big.size())
                {
                    small.insert(*big.begin());
                    big.erase(big.begin());
                }
            }
            else
            {
                auto iter = big.find(k);
                big.erase(iter);
                if (small.size() - big.size() > 1)
                {
                    big.insert(*small.begin());
                    small.erase(small.begin());
                }
            }
            if (r - l >= k)
            {
                maxx = max(maxx, *small.begin());
            }
        }
    }
    while (l < n)
    {
        int k = a[l++];
        if (k <= *small.begin())
        {
            auto iter = small.find(k);
            small.erase(iter);
            if (small.size() < big.size())
            {
                small.insert(*big.begin());
                big.erase(big.begin());
            }
        }
        else
        {
            auto iter = big.find(k);
            big.erase(iter);
            if (small.size() - big.size() > 1)
            {
                big.insert(*small.begin());
                small.erase(small.begin());
            }
        }
        if (r - l >= k)
        {
            maxx = max(maxx, *small.begin());
        }
    }
    cout << maxx << endl;
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

    solve();
    Please AC;
}