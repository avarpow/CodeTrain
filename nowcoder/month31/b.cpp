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
char num[5][600] = {
    "###..########.################...",
    "#.#..#..#..##.##..#..#.##.##.#.#.",
    "#.#..#################.##########",
    "#.#..##....#..#..##.#..##.#..#.#.",
    "###..#######..#######..#######...",
};
void solve()
{
    char s[6][600];
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", s[i]);
    }
    long long sum = 0, now = 0;
    int col = 0;
    int len = strlen(s[0]);
    while (col < len)
    {
        int ans;
        for (int i = 0; i < 11; i++)
        {
            int flag = 1;
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (s[k][col + j] != num[k][i * 3 + j])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag == 1)
            {
                ans = i;
                break;
            }
        }
        // cout << "find ans " << ans << endl;
        if (ans == 10)
        {
            sum += now;
            now = 0;
        }
        else
        {
            now = now * 10;
            now += ans;
        }
        col += 4;
    }
    sum += now;
    now = 0;
    //cout << sum << endl;
    char out[6][600];
    int chai[100], curr = 0;
    while (sum != 0)
    {
        chai[curr++] = sum % 10;
        sum /= 10;
    }
    for (int i = 0, j = curr - 1; i < j; i++, j--)
    {
        swap(chai[i], chai[j]);
    }
    //cout << curr << endl;
    for (int i = 0; i < curr; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                out[k][i * 4 + j] = num[k][chai[i] * 3 + j];
            }
        }
        if (i == curr - 1)
        {
            for (int k = 0; k < 5; k++)
            {
                out[k][i * 4 + 3] = '\0';
            }
        }
        else
        {
            for (int k = 0; k < 5; k++)
            {
                out[k][i * 4 + 3] = '.';
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%s", out[i]);
        cout << endl;
    }
    cout << endl;
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