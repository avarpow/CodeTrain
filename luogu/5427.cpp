//UNAC
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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = (mat[i][j] == 'R');
        }
    }
    int row = -1, col = -1;
    vector<int> irr;
    for (int i = 0; i < n; i++)
    {
        if (temp[0][0] == temp[i][0])
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[0][j] != temp[i][j])
                {
                    v[i] = 1;
                    irr.push_back(i);
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[0][j] == temp[i][j])
                {
                    v[i] = 1;
                    irr.push_back(i);
                    row = i;
                    col = j;
                    break;
                }
            }
        }
    }
    // cout << "irr: ";
    // for (auto i : irr)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    if (irr.size() == n - 1)
    {
        vector<int> irr2;
        int seck;
        for (int k = 0; k < n; k++)
        {
            if (v[k] == 1)
            {
                // cout << "k " << k << endl;
                seck = k;
                for (int i = 0; i < n; i++)
                {
                    if (temp[k][0] == temp[i][0])
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if (temp[k][j] != temp[i][j])
                            {
                                irr2.push_back(i);
                                row = i;
                                col = j;
                                break;
                            }
                        }
                    }
                    else
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if (temp[k][j] == temp[i][j])
                            {
                                irr2.push_back(i);
                                row = i;
                                col = j;
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }
        // cout << "irr2: ";
        // for (auto m : irr2)
        // {
        //     cout << m << " ";
        // }
        // cout << endl;
        if (irr2.size() > 1)
        {
            flag = 0;
        }
        else
        {
            //cout << "row " << row << " col " << col << endl;
            //temp[row][col] = (temp[row][col] == 0);
            for (int i = 0; i < n; i++)
            {
                vector<int> vis2(n, 0);
                int irrco = 0, nrow, ncol;
                if (temp[seck][0] == temp[i][0])
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (temp[seck][j] != temp[i][j])
                        {
                            vis2[j] = 1;
                            ncol = j;
                            irrco++;
                        }
                    }
                }
                else
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (temp[seck][j] == temp[i][j])
                        {
                            vis2[j] = 1;
                            ncol = j;
                            irrco++;
                        }
                    }
                }
                //cout << "irrco " << irrco << endl;
                if (irrco == 1)
                {
                    col = ncol;
                }
                else if (irrco == n - 1)
                {
                    //cout << "irrco n-1 " << irrco << "flag" << flag << endl;
                    for (int j = 0; j < n; j++)
                    {
                        if (vis2[j] == 0)
                        {
                            col = j;
                        }
                    }
                    break;
                }
                else
                    flag = 0;
            }
        }
    }
    else if (irr.size() > 1)
    {
        flag = 0;
    }
    else
    {
        temp[row][col] = (temp[row][col] == 0);
        for (int i = 0; i < n; i++)
        {
            if (temp[0][0] == temp[i][0])
            {
                for (int j = 0; j < n; j++)
                {
                    if (temp[0][j] != temp[i][j])
                    {
                        flag = 0;
                        break;
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
                        break;
                    }
                }
            }
        }
    }
#ifdef yn
    if (flag)
    {
        cout << row + 1 << " " << col + 1 << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
#endif
}
int main()
{
    solve();
    Please AC;
}