# 动态规划
class Solution:
    @staticmethod
    def maxSubArray(nums: list[int]) -> int:
        ans = [0 for _ in range(len(nums))]  # ans[i]表示以nums[i]结尾的连续子数组的最大和
        ans[0] = nums[0]
        for i in range(1, len(nums)):
            if ans[i - 1] < 0:
                ans[i] = nums[i]
            else:
                ans[i] = ans[i - 1] + nums[i]
            # ans[i] = max(ans[i - 1] + nums[i], nums[i])
        return max(ans)
