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
using namespace std;
void solve()
{
    long long n, flag = 0;
    cin >> n;
    int mod = n % 2020;
    int yu = n / 2020;
    //cout << "mod " << mod << "yu " << yu << endl;
    if (mod <= yu)
    {
        flag = 1;
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