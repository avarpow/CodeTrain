class Solution
{
public:
    int minOperations(string s)
    {
        int len = s.size();
        int c = 0;
        for (int i = 0; i < len; i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '0')
                    c++;
            }
            else
            {
                if (s[i] == '1')
                    c++;
            }
        }
        return min(c, len - c);
    }
};