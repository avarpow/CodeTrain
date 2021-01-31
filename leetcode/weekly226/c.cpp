class Solution
{
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
    {
        vector<long long> sum(candiesCount.size());
        sum[0] = candiesCount[0];
        for (int i = 1; i < candiesCount.size(); i++)
        {
            sum[i] = sum[i - 1] + candiesCount[i];
        }
        vector<bool> ret;
        for (auto &k : queries)
        {
            long long daily = k[2], day = k[1] + 1, fav = k[0];
            if (!(day > sum[fav]) && !(fav - 1 >= 0 && daily * day <= sum[fav - 1]))
            {
                ret.push_back(true);
            }
            else
            {
                ret.push_back(false);
            }
        }
        return ret;
    }
};