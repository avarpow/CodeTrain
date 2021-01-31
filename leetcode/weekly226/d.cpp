class Solution
{
public:
    bool chk(int l, int r, int vis[][2010], string &s)
    {
        // cout<<"l"<<l<<"r"<<r<<endl;

        if (vis[l][r] != 0)
        {
            if (vis[l][r] == 2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (r - l == 1)
            {
                if (s[l] == s[r])
                {
                    vis[l][r] = 2;
                    return true;
                }
                else
                {
                    vis[l][r] = 1;
                    return false;
                }
            }
            else
            {
                bool res = false;
                if (s[l] == s[r])
                {
                    res = chk(l + 1, r - 1, vis, s);
                }
                if (res)
                {
                    vis[l][r] = 2;
                }
                else
                {
                    vis[l][r] = 1;
                }
                return res;
            }
        }
    }
    bool checkPartitioning(string s)
    {
        int vis[2010][2010] = {0};
        int n = s.size();
        for (int i = 0; i <= n; i++)
        {
            vis[i][i] = 2;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                //cout<<i<<" "<<j<<endl;
                if (chk(0, i, vis, s) && chk(i + 1, j, vis, s) && chk(j + 1, n - 1, vis, s))
                {
                    return true;
                }
            }
        }
        return false;
    }
};