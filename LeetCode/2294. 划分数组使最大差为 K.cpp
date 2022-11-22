class Solution
{
public:
    static int partitionArray(vector<int> &nums, int k)
    {
        sort(begin(nums), end(nums));
        int cnt = 1;
        int tmp = nums[0];
        // 将差超过k的单独分组，之后的分到新的一组，直到差再次超过k
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] - tmp > k)
            {
                ++cnt;
                tmp = nums[i];
            }
        }
        return cnt;
    }
};
