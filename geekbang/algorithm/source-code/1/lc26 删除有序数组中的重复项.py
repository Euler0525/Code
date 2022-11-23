class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = 0
        for i in range(0, len(nums)):
            if i == 0 or nums[i] != nums[i - 1]:
                nums[n] = nums[i]
                n += 1
        return n