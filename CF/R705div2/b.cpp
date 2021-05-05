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
vector<int> vec;
int a[5] = {0, 1, 2, 5, 8};
void solve()
{
    int h, m, flag = 0;
    cin >> h >> m;
    int nowh, nowm;
    scanf("%d:%d", &nowh, &nowm);
    int nowt = nowh * 100 + nowm;
    for (auto i : vec)
    {
        int w[4];
        w[0] = i / 1000;
        w[1] = i / 100 % 10;
        w[2] = i / 10 % 10;
        w[3] = i % 10;
        int kh = w[0] * 10 + w[1];
        int km = w[2] * 10 + w[3];
        if (kh >= h)
        {
            break;
        }
        if (km >= m)
        {
            continue;
        }
        for (int j = 0; j < 4; j++)
        {
            if (w[j] == 2)
            {
                w[j] = 5;
            }
            else if (w[j] == 5)
            {
                w[j] = 2;
            }
        }
        int revh = w[3] * 10 + w[2];
        int revm = w[1] * 10 + w[0];
        if (nowt <= i && revh < h && revm < m)
        {
            //cout << "i " << i << endl;
            if (kh < 10)
                cout << "0";
            cout << kh << ":";
            if (km < 10)
                cout << "0";
            cout << km << endl;
            return;
        }
    }
    cout << "00:00" << endl;
    return;
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
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    int time = a[i] * 1000 + a[j] * 100 + a[k] * 10 + a[l];
                    vec.push_back(time);
                }
            }
        }
    }
    sort(vec.begin(), vec.end());
    for (auto i : vec)
    {
        //cout << "= " << i << " ";
    }
    while (n--)
        solve();
    Please AC;
}