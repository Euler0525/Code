class Solution:
    def minimumSum(self, num: int) -> int:
        nums = sorted(list(str(num)))
        return int("{}{}".format(nums[0], nums[-1])) + int("{}{}".format(nums[1], nums[-2]))
