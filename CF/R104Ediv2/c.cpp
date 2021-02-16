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
int adj[200][200] = {0};
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void solve()
{
    memset(adj, 0, sizeof(adj));
    int n, flag = 0;
    cin >> n;
    int k = n * (n - 1) / 2;
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            if (n % i == 0 && n / i > 2)
            {
                int t = 1;
                //mycout << " i " << i << endl;
                for (int k = 0; k < i; k++)
                {
                    for (int j = 1 + k; j <= n; j += i)
                    {
                        int nxt = j + i;
                        if (nxt > n)
                        {
                            nxt -= n;
                        }
                        adj[j][nxt] = t;
                        //mycout << j << " " << nxt << " t " << t << endl;
                        adj[nxt][j] = t ^ 1 ^ -1;
                    }
                }
            }
            else if (n % i != 0)
            {
                int k = gcd(n, i);
                //mycout << i << endl;
                int t = 1;
                for (int m = 0; m < k; m++)
                {
                    for (int j = 0; j < n / k; j++)
                    {
                        adj[j * i % n + m + 1][(j + 1) * i % n + m + 1] = t;
                        adj[(j + 1) * i % n + m + 1][j * i % n + m + 1] = t ^ 1 ^ -1;
                        //mycout << j * i % n + m + 1 << " " << (j + 1) * i % n + m + 1 << " t " << t << endl;
                    }
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                printf("%d%s", adj[i][j], i == n - 1 && j == n ? "\n" : " ");
            }
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                printf("%d%s", (i + j) % 2 == 0 ? -1 : 1, i == n - 1 && j == n ? "\n" : " ");
            }
        }
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