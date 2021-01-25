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
int coa[200005], cob[200005];
pair<int, int> pa[200005];
void solve()
{
    int a, b, k;
    cin >> a >> b >> k;

    memset(pa, 0, sizeof(pa));
    memset(coa, 0, sizeof(coa));
    memset(cob, 0, sizeof(cob));
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        coa[t]++;
        pa[i].first = t;
    }

    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        cob[t]++;
        pa[i].second = t;
    }
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += (k - coa[pa[i].first] - cob[pa[i].second] + 1);
    }
    cout << ans / 2 << endl;
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