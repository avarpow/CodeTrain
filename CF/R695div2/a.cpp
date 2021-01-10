#include <iostream>
using namespace std;
void solve()
{
    int a;
    cin >> a;
    int now = 9;
    if (a == 1)
    {
        cout << 9;
    }
    else
    {
        cout << 98;
        int now = 9;
        for (int i = 2; i < a; i++)
        {
            cout << now;
            now++;
            if (now > 9)
                now = 0;
        }
    }
    cout << endl;
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
}