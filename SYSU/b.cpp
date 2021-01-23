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
int gf(int a, vector<int> &f)
{
    if (f[a] != a)
    {
        f[a] = gf(f[a], f);
    }
    return f[a];
}
void solve()
{
    int n, m;
    vector<int> f;
    vector<pair<int, int>> res;
    cin >> n >> m;
    f.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (gf(a, f) != gf(b, f))
        {
            f[gf(a, f)] = gf(b, f);
        }
    }
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        if (gf(i, f) != gf(i + 1, f))
        {
            c++;
            res.emplace_back(i, i + 1);
            f[gf(i, f)] = gf(i + 1, f);
        }
    }
    cout << res.size() << endl;
    for (auto i : res)
    {
        printf("%d %d\n", i.first, i.second);
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

    solve();
    Please AC;
}