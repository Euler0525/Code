# 双指针
class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        nums = list()
        p1 = p2 = 0
        while p1 < m and p2 < n:
            if nums1[p1] > nums2[p2]:
                nums.append(nums2[p2])
                p2 += 1
            else:
                nums.append(nums1[p1])
                p1 += 1

        if p1 == m:
            nums += nums2[p2:n]
        else:
            nums += nums1[p1:m]

        nums1[:] = nums

# # 合并排序
# class Solution:
#     def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
#         nums1[m:] = nums2
#         nums1.sort()
