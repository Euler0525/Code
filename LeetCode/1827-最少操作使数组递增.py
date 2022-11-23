class Solution:
    def minOperations(self, nums: list[int]) -> int:
        cnt = 0
        if len(nums) == 0 or len(nums) == 1:
            return cnt

        for i in range(len(nums) - 1):
            if nums[i + 1] <= nums[i]:
                tmp = nums[i] - nums[i + 1]
                cnt += (tmp + 1)
                nums[i + 1] += (tmp + 1)
        return cnt
