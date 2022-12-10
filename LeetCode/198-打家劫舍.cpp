# include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        // 子问题：
        // f(k) = 偷 [0..k) 房间中的最大金额
        // f(0) = 0
        // f(1) = nums[0]
        // f(k) = max{ rob(k-1), nums[k-1] + rob(k-2) }
        int length = nums.size();
        vector<int> dp(length + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int k = 2; k <= length; k++)
        {
            dp[k] = max(dp[k - 1], nums[k - 1] + dp[k - 2]);
        }
        return dp[length];
    }
};
