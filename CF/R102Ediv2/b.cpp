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
int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}
void solve()
{
    string a, b;
    cin >> a >> b;
    int ca, cb;
    for (int i = 1; i <= a.size(); i++)
    {
        if (a.size() % i == 0)
        {
            ca = 0;
            for (int j = 0; j < a.size(); j += i)
            {
                for (int k = 0; k < i; k++)
                {
                    if (a[k] != a[j + k])
                    {
                        ca = -1;
                    }
                }
            }
            if (ca != -1)
            {
                ca = a.size() / i;
                //cerr << "ca find size " << ca << endl;
            }

            cb = 0;
            for (int j = 0; j < b.size(); j += i)
            {
                for (int k = 0; k < i; k++)
                {
                    if (a[k] != b[j + k])
                    {
                        cb = -1;
                    }
                }
            }
            if (cb != -1)
            {
                cb = b.size() / i;
                //cerr << "cb find size " << cb << endl;
            }
            if (ca != -1 && cb != -1)
            {
                int countt = ca / gcd(ca, cb);
                //cerr << "gcd find size " << gcd(ca, cb) << endl;
                //cerr << "countt find size " << countt << endl;
                for (int j = 0; j < countt; j++)
                {
                    cout << b;
                }
                cout << endl;
                break;
            }
        }
    }
    //cerr << "final ca " << ca << " cb " << cb << endl;
    if (cb == -1)
    {
        cout << -1 << endl;
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