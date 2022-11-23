class Solution
{
public:
    static int balancedStringSplit(const string &s)
    {
        int cnt = 0, flag = 0;
        for (auto i: s)
        {
            i == 'L' ? flag += 1 : flag -= 1;
            cnt = flag == 0 ? cnt + 1 : cnt;
        }
        return cnt;
    }
};