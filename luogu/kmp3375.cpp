//kmp
/* 注意要点：
    1.将字符串从1开始读取和处理，可以不用将那next数组向后移位
    2.匹配过程三种情况，1.当前j!=0,失去匹配，j=next[j] 2.当前匹配，j++ 
        对于next数组的构建过程，处理前两种情况之后需要复制next[j]=j
    3.创建next数组的过程就是自己匹配自己的过程
    4.判断是否完全匹配的过程就是j==匹配字符串的长度
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;
#define N 16
int main()
{
    char s[N], p[N];
    int nxt[N];
    cin >> s + 1;
    cin >> p + 1;
    int lens = strlen(s + 1);
    int lenp = strlen(p + 1);
    int j = 0;
    nxt[1] = 0;
    for (int i = 2; i <= lenp; i++)
    {
        while (j && p[i] != p[j + 1])
        {
            j = nxt[j];
        }
        if (p[i] == p[j + 1])
        {
            j++;
        }
        nxt[i] = j;
    }
    j = 0;
    for (int i = 1; i <= lens; i++)
    {
        while (j && s[i] != p[j + 1])
        {
            j = nxt[j];
        }
        if (s[i] == p[j + 1])
        {
            j++;
        }
        if (j == lenp)
        {
            cout << i - lenp + 1 << endl;
            j = nxt[j];
        }
    }
    for (int i = 1; i <= lenp; i++)
    {
        cout << nxt[i] << " ";
    }
    cout << endl;
    return 0;
}