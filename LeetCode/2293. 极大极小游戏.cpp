class Solution
{
public:
    static int minMaxGame(vector<int> &nums)
    {
        auto n = nums.size();
        while (n != 1)
        {
            for (int i = 0; i < n; i += 2)
            {
                ((i / 2) & 1) == 0 ? nums[i / 2] = min(nums[i], nums[i + 1]) : nums[i / 2] = max(nums[i], nums[i + 1]);
            }
            n >>= 1;
        }

        return nums[0];
    }
};
