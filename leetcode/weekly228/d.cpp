class Solution
{
public:
    int minTrioDegree(int n, vector<vector<int>> &edges)
    {
        vector<int> d(n + 4);
        vector<vector<int>> adj(n + 4, vector<int>(n + 4));
        for (auto &i : edges)
        {
            adj[i[0]][i[1]] = 1;
            adj[i[1]][i[0]] = 1;
            d[i[0]]++;
            d[i[1]]++;
        }
        int minn = 999999999;
        for (int i = 0; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++) //如果这里j=0过不了
            {
                if (adj[i][j] != 1 || minn == 0) //如果这里不卡常数65/68
                {
                    continue;
                }
                for (int k = j + 1; k <= n; k++)
                {
                    if (i != j && i != k && j != k)
                    {
                        if (adj[i][j] == 1 && adj[i][k] == 1 && adj[j][k] == 1)
                        {
                            int now = d[i] + d[j] + d[k] - 6;
                            minn = min(minn, now);
                        }
                    }
                }
            }
        }
        if (minn == 999999999)
        {
            return -1;
        }
        else
        {
            return minn;
        }
    }
};