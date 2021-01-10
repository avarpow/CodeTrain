//wrong
/* 令a[i]=a[i-1] 或者a[i]=a[i+1] 重新计算即可 偷懒没有写正解*/
/* #include <iostream>
using namespace std;
int a[300005];
int d[300005];
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        d[i] = 0;
    }
    if (n <= 3)
    {
        cout << 0 << endl;
        return;
    }
    int maxdis = 0;
    int sum = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            sum++;
            d[i] = 1;
        }
        else if (a[i] < a[i - 1] && a[i] < a[i + 1])
        {
            sum++;
            d[i] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl
         << sum << endl;
    for (int i = 1; i < n - 1; i++)
    {
        int t;
        int tmax;
        if (d[i - 1] == -1 && d[i + 1] == 1 || d[i - 1] == 1 && d[i + 1] == -1)
        {
            tmax = 1;
        }
        else if (d[i - 1] == -1 && d[i + 1] == -1 || d[i - 1] == 1 && d[i + 1] == 1)
        {
            tmax = 3;
        }
        else
        {
            tmax = abs(d[i - 1]) + abs(d[i]) + abs(d[i + 1]);
        }
        maxdis = max(tmax, maxdis);
    }
    cout << sum - maxdis << endl;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
} */