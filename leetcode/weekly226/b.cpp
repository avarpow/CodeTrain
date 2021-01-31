class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        int vis[300000] = {0};
        vector<int> adj[300000];
        for (auto &i : adjacentPairs)
        {
            adj[i[0] + 150000].push_back(i[1] + 150000);
            adj[i[1] + 150000].push_back(i[0] + 150000);
        }
        vector<int> start;
        for (int i = 0; i < 300000; i++)
        {
            if (adj[i].size() == 1)
            {
                start.push_back(i - 150000);
            }
        }
        vector<int> ret;
        ret.push_back(start[0]);
        cout << start[0] << endl;
        int now = start[0];
        vis[start[0] + 150000] = 1;
        for (int i = 0; i < adjacentPairs.size(); i++)
        {
            if (adj[now + 150000].size() == 0)
            {
                //cout<<"error"<<endl;
            }
            else if (adj[now + 150000].size() == 1)
            {
                if (vis[adj[now + 150000][0]] == 0)
                {
                    vis[adj[now + 150000][0]] = 1;
                    ret.push_back(adj[now + 150000][0] - 150000);
                    now = adj[now + 150000][0] - 150000;
                }
            }
            else
            {
                if (vis[adj[now + 150000][0]] == 0)
                {
                    vis[adj[now + 150000][0]] = 1;
                    ret.push_back(adj[now + 150000][0] - 150000);
                    now = adj[now + 150000][0] - 150000;
                }
                else
                {
                    vis[adj[now + 150000][1]] = 1;
                    ret.push_back(adj[now + 150000][1] - 150000);
                    now = adj[now + 150000][1] - 150000;
                }
            }
        }
        return ret;
    }
};