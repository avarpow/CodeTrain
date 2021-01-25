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
string mat[2000];
string goal[2000];
int temp[2000][2000];
void solve()
{
    int n, flag = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> goal[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = (mat[i][j] == goal[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (temp[0][0] == temp[i][0])
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[0][j] != temp[i][j])
                {
                    flag = 0;
                }
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[0][j] == temp[i][j])
                {
                    flag = 0;
                }
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