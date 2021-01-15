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
using namespace std;
int main()
{
    freopen("in.in", "w", stdout);
    cout << 1 << endl;
    int n = 10005, m = 10;
    cout << n << " " << m - 1 << endl;
    for (int i = 0; i < n / 2; i++)
    {
        cout << "+";
    }
    for (int i = n / 2; i < n; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 1; i < m; i++)
    {
        cout << i * 1000 << " " << (m - i) * 1000 + 5 << endl;
    }
    Please AC;
}