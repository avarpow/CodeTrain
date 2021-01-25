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
int a[200005];
int one[200005];
int two[200005];
void solve()
{
    int sizeone = 0, sizetwo = 0;
    long long n, m, flag = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            one[sizeone++] = a[i];
        }
        else
        {
            two[sizetwo++] = a[i];
        }
    }
    sort(one, one + sizeone, greater<int>());
    sort(two, two + sizetwo, greater<int>());
    long long now = 0, curone = 0, curtwo = 0;
    int ans = 0;
    while (now < m && curone < sizeone && curtwo < sizetwo)
    {
        if (one[curone] >= two[curtwo])
        {
            now += one[curone];
            ans++;
            curone++;
            //cout << "one > 2  " << ans << endl;
        }
        else if (now + one[curone] >= m)
        {
            now += one[curone];
            ans++;
            curone++;
            //cout << "in ok" << ans << endl;
        }
        else if (curone == sizeone - 1)
        {
            now += two[curtwo];
            ans += 2;
            curtwo++;
            //cout << "one left 1" << ans << endl;
        }
        else if (curone < sizeone - 1)
        {
            if (now + one[curone] + one[curone + 1] >= m)
            {
                now += (one[curone] + one[curone + 1]);
                ans += 2;
                curone += 2;
            }
            else if (now + one[curone] + two[curtwo] >= m)
            {
                now += (one[curone] + two[curtwo]);
                ans += 3;
                curone++;
                curtwo++;
                //cout << "ad 3" << ans << endl;
            }
            else if (one[curone] + one[curone + 1] > two[curtwo])
            {
                now += (one[curone] + one[curone + 1]);
                ans += 2;
                curone += 2;
            }
            else
            {
                now += two[curtwo];
                ans += 2;
                curtwo++;
            }
        }
    }
    while (now < m && curone < sizeone)
    {
        now += one[curone];
        ans++;
        curone++;
    }
    while (now < m && curtwo < sizetwo)
    {
        now += two[curtwo];
        ans += 2;
        curtwo++;
    }
    if (now < m)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
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