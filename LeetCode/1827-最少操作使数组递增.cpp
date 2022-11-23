class Solution
{
public:
    static int minOperations(vector<int> &nums)
    {
        int tmp = 0, cnt = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] >= nums[i + 1])
            {
                tmp = nums[i] - nums[i + 1] + 1;
                nums[i + 1] += tmp;
                cnt += tmp;
            }
        }
        return cnt;
    }
};