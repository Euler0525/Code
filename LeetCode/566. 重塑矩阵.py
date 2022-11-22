class Solution:
    @staticmethod
    def matrixReshape(nums: list[list[int]], r: int, c: int) -> list[list[int]]:
        m, n = len(nums), len(nums[0])
        if m * n != r * c:
            return nums

        ans = [[0] * c for _ in range(r)]
        for x in range(m * n):
            ans[x // c][x % c] = nums[x // n][x % n]

        return ans
