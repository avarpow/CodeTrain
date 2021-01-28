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
#define yn
#define mycout cout
using namespace std;
long long b[200005];
long long a[100005];
long long test[200005];
long long testd[200005];
long long divv[100005];
long long divns[100005];
void solve()
{
    long long n, flag = 1;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%lld", &b[i]);
    }
    sort(b, b + 2 * n);
    long long sum = a[0];
    for (int i = 0; i < n; i++)
    {
        if (b[2 * i + 1] != b[2 * i])
        {
            flag = 0;
        }
        a[i] = b[2 * i];
        //mycout << a[i] << " " << a[i] << " ";
    }
    //mycout << endl;
    for (int i = 0; i < n - 1; i++)
    {
        divv[i] = a[i + 1] - a[i];
    }
    long long now = 2;
    long long alldiv = 0;
    for (long long i = 0; i < n - 1; i++)
    {
        if ((divv[i] % now) != 0 || divv[i] == 0)
        {
            //mycout << "no mod" << endl;
            flag = 0;
            break;
        }
        divns[i] = divv[i] / now;
        alldiv += (long long)(n - i - 1) * divns[i];
        now += 2;
    }
    if (a[0] % 2 == 1)
        flag = 0;
    sum = a[0] / 2;

    //mycout << "sum " << sum << endl;
    //mycout << "alldiv " << alldiv << endl;
    //mycout << "divns" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        //mycout << divns[i] << " ";
    }
    //mycout << endl;
    if ((sum - alldiv) <= 0 || ((sum - alldiv) % n != 0))
    {
        //mycout << "get a0 fail" << endl;
        flag = 0;
    }
    // long long a0 = (sum - alldiv) / n;
    // test[0] = a0;
    // test[n] = -a0;
    // for (int i = 1; i < n; i++)
    // {
    //     test[i] = test[i - 1] + divns[i - 1];
    //     test[n + i] = -test[i];
    // }
    // for (int i = 0; i < 2 * n; i++)
    // {
    //     long long tempd = 0;
    //     for (int j = 0; j < 2 * n; j++)
    //     {
    //         tempd += abs(test[i] - test[j]);
    //     }
    //     testd[i] = tempd;
    // }
    // sort(testd, testd + 2 * n);
    // for (int i = 0; i < 2 * n; i++)
    // {
    //     mycout << testd[i] << " ";
    // }
    // mycout << endl;
    //mycout << "a0 " << a0 << endl;
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