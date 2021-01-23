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
char s[200000];
int num[200000];
int res[200000];
int bins[200000];
int main()
{
    clock_t start, end;
    start = clock();
    freopen("in.in", "r", stdin);
    int n;
    int k = 0;
    char t;
    while ((t = getchar()) != EOF)
    {
        s[k++] = t;
    }
    end = clock();
    cout << "time = " << double(end - start) << "ms" << endl;
    start = clock();

    int len = strlen(s);
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
    for (int i = 0; i < len; i++)
    {
        num[i] = s[i] - '0';
    }
    int maxwei = len - 1;
    int binlen = 0;
    while (maxwei >= 0)
    {
        // printf("now int");
        for (int i = 0; i <= maxwei; i++)
        {
            // printf("%d", num[i]);
        }
        // cout << endl;
        bins[binlen++] = num[0] % 2;
        num[0] -= (num[0] % 2);
        int now = maxwei;
        for (int i = maxwei; i >= 0; i--)
        {
            if (i == now)
            {
                res[i] = num[i] % 2;
                num[i] = num[i] / 2;
                if (num[i] == 0)
                {
                    maxwei--;
                }
                // printf("solve maxwei res %d num %d\n", res[i], num[i]);
            }
            else
            {
                int temp = res[i + 1] * 10 + num[i];
                res[i] = num[i] % 2;
                num[i] = temp / 2;
                // printf("solve wei %d temp %d res %d num %d\n", i, temp, res[i], num[i]);
            }
        }
    }
    for (int i = 0; i < binlen; i++)
    {
        printf("%d", bins[i]);
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
    cout << "time = " << double(end - start) << "ms" << endl;
    Please AC;
}