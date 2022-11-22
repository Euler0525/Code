class Solution
{
public:
    static int countGoodSubstrings(const string &s)
    {
        int cnt = 0;
        if (s.empty() || s.size() == 1 || s.size() == 2)
        {
            return 0;
        }
        for (int i = 0; i < s.size() - 2; ++i)
        {
            if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2])
            {
                ++cnt;
            }
        }

        return cnt;
    }
};