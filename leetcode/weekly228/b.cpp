class Solution
{
public:
    int countHomogenous(string s)
    {
        int now = s[0];
        int c = 0;
        long long ans = 0;
        for (auto i : s)
        {
            if (i == now)
                c++;
            else
            {
                ans += (long long)c * (c + 1) / 2;
                ans = ans % 1000000007;
                now = i;
                c = 1;
            }
        }
        ans += (long long)c * (c + 1) / 2;
        ans = ans % 1000000007;
        return ans;
    }
};