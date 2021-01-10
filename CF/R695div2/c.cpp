/* wrong */
/* 第一种情况为从两个不同的集合中选两个神，把第三个集合内保留一个元素，其他的元素被两个神元素减去，然后再用第三个集合
    保留的元素去减去两个神，则答案为sum-两个神x2
    第二种情况为从同一个集合里面选两个神，这种情况下同一个集合里面的所有元素都要被减掉（因为不像第一种情况可以被另一个集合里面的神所接收）
    则答案为sum- 一个集合的全部元素x2
*/
/* #include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int m[300005];
void solve()
{
    vector<int> t;
    int a, b, c;
    cin >> a >> b >> c;
    long long sum = 0;
    long long odd = 0;
    for (int i = 0; i < a + b + c; i++)
    {
        scanf("%d", &m[i]);
    }
    sort(m, m + a + b + c);
    for (int i = 0; i < (a + b + c) / 2; i++)
    {
        odd += m[i];
    }
    if (sum - odd > odd)
    {
        odd = sum - odd;
    }
    cout << odd << endl;
}
int main()
{
    // int n;
    // cin >> n;
    // while (n--)
    // {
    solve();
    // }
    return 0;
} */