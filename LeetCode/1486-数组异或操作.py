import functools


# 模拟
class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        nums = list()
        for i in range(n):
            nums.append(start + 2 * i)
        return functools.reduce(self.func, nums)

    @staticmethod
    def func(a: int, b: int) -> int:
        return a ^ b

# 简化代码
# class Solution:
#     @staticmethod
#     def xorOperation(n: int, start: int) -> int:
#         ans = 0
#         for i in range(n):
#             ans ^= (start + i * 2)
#         return ans
