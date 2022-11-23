class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        nums = nums1 + nums2
        nums.sort()

        length = len(nums)

        if length % 2 == 0:
            return (nums[int(length / 2)] + nums[int(length / 2 - 1)]) / 2
        else:
            return nums[int((length - 1) / 2)]
