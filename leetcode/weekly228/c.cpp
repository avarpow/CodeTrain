class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int high = 1099999999;
        int low = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        while (high - low > 1)
        {
            int mid = (high + low) / 2;

            if (check(nums, maxOperations, mid))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        return high;
    }
    bool check(vector<int> &nums, int maxOperations, int high)
    {
        vector<int> t(nums);
        int c = 0;
        for (auto i : t)
        {
            if (i <= high)
            {
                break;
            }
            else
            {
                int m = i % high;
                if (m != 0)
                {
                    c += (i / high);
                }
                else
                {
                    c += (i / high - 1);
                }
            }
        }

        return c <= maxOperations;
    }
};