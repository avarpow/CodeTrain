#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <time.h>
#define Please return
#define AC 0
// #define yn
using namespace std;
#define mod 998244353
void solve()
{
    int n, flag = 0;
    cin >> n;

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
char s[200000] = {0};
long long tei[200000] = {0};
long long num[200000] = {0};
long long res[200000] = {0};
int bins[200000] = {0};
int main()
{
    clock_t start, end;
    start = clock();
    //freopen("in.in", "r", stdin);
    int n;
    int k = 0;
    char t;
    while ((t = getchar()) != EOF && t != '\n')
    {

        s[k++] = t;
    }
    // end = clock();
    // // cout << "time = " << double(end - start) << "ms" << endl;
    // start = clock();

    int len = strlen(s);

    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
    for (int i = 0; i < len; i++)
    {
        tei[i] = s[i] - '0';
    }
    for (int i = 0; i < len; i += 15)
    {
        num[i / 15] = (tei[i]);
        num[i / 15] += (tei[i + 1]) * 1e1;
        num[i / 15] += (tei[i + 2]) * 1e2;
        num[i / 15] += (tei[i + 3]) * 1e3;
        num[i / 15] += (tei[i + 4]) * 1e4;
        num[i / 15] += (tei[i + 5]) * 1e5;
        num[i / 15] += (tei[i + 6]) * 1e6;
        num[i / 15] += (tei[i + 7]) * 1e7;
        num[i / 15] += (tei[i + 8]) * 1e8;
        num[i / 15] += (tei[i + 9]) * 1e9;
        num[i / 15] += (tei[i + 10]) * 1e10;
        num[i / 15] += (tei[i + 11]) * 1e11;
        num[i / 15] += (tei[i + 12]) * 1e12;
        num[i / 15] += (tei[i + 13]) * 1e13;
        num[i / 15] += (tei[i + 14]) * 1e14;
        // cout << " num[i/5] " << num[i / 15] << endl;
    }
    int maxwei = (len) / 15;
    int binlen = 0;
    while (maxwei >= 0)
    {
        // printf("now int");
        for (int i = 0; i <= maxwei; i++)
        {
            // printf("%d", num[i]);
        }
        // cout << endl;

        bins[binlen] = num[0] & (1 << 0) ? 1 : 0;
        bins[binlen + 1] = num[0] & (1 << 1) ? 1 : 0;
        bins[binlen + 2] = num[0] & (1 << 2) ? 1 : 0;
        bins[binlen + 3] = num[0] & (1 << 3) ? 1 : 0;
        bins[binlen + 4] = num[0] & (1 << 4) ? 1 : 0;
        bins[binlen + 5] = num[0] & (1 << 5) ? 1 : 0;
        bins[binlen + 6] = num[0] & (1 << 6) ? 1 : 0;
        bins[binlen + 7] = num[0] & (1 << 7) ? 1 : 0;
        bins[binlen + 8] = num[0] & (1 << 8) ? 1 : 0;
        bins[binlen + 9] = num[0] & (1 << 9) ? 1 : 0;
        bins[binlen + 10] = num[0] & (1 << 10) ? 1 : 0;
        bins[binlen + 11] = num[0] & (1 << 11) ? 1 : 0;
        bins[binlen + 12] = num[0] & (1 << 12) ? 1 : 0;
        binlen += 13;
        //num[0] -= (num[0] % 16384);
        int now = maxwei;
        for (int i = maxwei; i >= 0; i--)
        {
            if (i == now)
            {
                res[i] = num[i] % (1 << 13);
                num[i] = num[i] / (1 << 13);
                if (num[i] == 0)
                {
                    maxwei--;
                }
                // printf("solve maxwei res %d num %d\n", res[i], num[i]);
            }
            else
            {
                long long temp = res[i + 1] * 1e15 + num[i];
                res[i] = num[i] % (1 << 13);
                num[i] = temp / (1 << 13);
                // printf("solve wei %d temp %d res %d num %d\n", i, temp, res[i], num[i]);
            }
        }
    }
    end = clock();
    //cout << "time = " << double(end - start) << "ms" << endl;
    start = clock();
    for (int i = 0; i < binlen; i++)
    {
        //printf("%d", bins[i]);
    }
    long long ans = 1;
    if (bins[0] == 1)
    {
        ans = 4;
    }
    long long now = 6;
    for (int i = 1; i < binlen; i++)
    {
        if (bins[i] == 1)
        {
            ans *= now;
            ans = ans % mod;
        }
        now = now * now;
        now = now % mod;
    }
    cout << ans << endl;
    end = clock();
    //cout << "time = " << double(end - start) << "ms" << endl;
    Please AC;
}