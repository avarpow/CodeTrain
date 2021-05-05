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
char s[200006];
char sb[200006];
void add(int k)
{
    if (k < 0)
        return;
    if (s[k] == 'z')
    {
        s[k] = 'a';
        add(k - 1);
    }
    else
    {
        s[k]++;
    }
}
int check(int x, int y, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (s[x + i] < s[y + i])
        {
            return -1;
        }
        else if (s[x + i] > s[y + i])
        {
            return 1;
        }
    }
    return 0;
}
void solve()
{
    int n, k;
    int flag = 0;
    cin >> n >> k;
    int index = 0;
    scanf("%s", s);
    if (n % k != 0)
    {
        cout << -1 << endl;
        return;
    }
    if (k == 1)
    {
        printf("%s\n", s);
        return;
    }
    int len = strlen(s);
    for (int i = k; i < len; i += k, index++)
    {
        if (check(0, i, k) == 1)
        {
            break;
        }
        else if (check(0, i, k) == -1)
        {
            flag = -1;
            break;
        }
    }
    if (flag == -1)
    {
        add(k - 1);
        s[k] = '\0';
        for (int i = 0; i < n / k; i++)
        {
            printf("%s", s);
        }
        printf("\n");
    }
    else
    {
        s[k] = '\0';
        strcpy(sb, s);
        sort(sb, sb + k);
        for (int i = 0; i < n / k; i++)
        {
            if (i < index + 1)
            {
                printf("%s", s);
            }
            else
            {
                printf("%s", sb);
            }
        }
        printf("\n");
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