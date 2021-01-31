class Solution
{
public:
    int countBalls(int lowLimit, int highLimit)
    {
        int a[100] = {0};
        for (int i = lowLimit; i <= highLimit; i++)
        {
            int k = i;
            int sum = 0;
            while (k > 0)
            {
                sum += k % 10;
                k = k / 10;
            }
            a[sum]++;
        }
        int maxxin = -1;
        int maxx = 0;
        for (int i = 0; i < 100; i++)
        {
            if (a[i] > maxx)
            {
                maxxin = i;
                maxx = a[i];
            }
        }
        return maxx;
    }
};