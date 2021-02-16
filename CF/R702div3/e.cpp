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
struct p
{
    long long a;
    long long index;
} ps[200006];
long long sum[200006] = {0};
int cmp(p a, p b)
{
    return a.a < b.a;
}
void solve()
{
    int n, flag = 0;
    cin >> n;
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &ps[i].a);
        ps[i].index = i + 1;
    }
    sort(ps, ps + n, cmp);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + ps[i].a;
    }
    long long nowwin = ps[n - 1].a;
    vector<int> ret;
    for (int i = n - 1; i >= 0; i--)
    {
        if (sum[i] + ps[i].a >= nowwin)
        {
            //cout << " i " << i << " sum " << sum[i] << endl;
            ret.push_back(ps[i].index);
            nowwin = ps[i].a;
            //cout << "nowwin " << ps[i].a << endl;
            while (i > 0 && ps[i].a == ps[i - 1].a)
            {
                i--;
                ret.push_back(ps[i].index);
            }
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++)
    {
        printf("%d%s", ret[i], i == ret.size() - 1 ? "\n" : " ");
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