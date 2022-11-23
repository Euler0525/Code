class Solution:
    def trap(self, heights: List[int]) -> int:
        n = len(heights)
        preMax = [0] * n
        sufMax = [0] * n
        preMax[0] = heights[0]
        for i in range(1, n):
            preMax[i] = max(preMax[i - 1], heights[i])
        sufMax[n - 1] = heights[n - 1]
        for i in range(n - 2, -1, -1):
            sufMax[i] = max(sufMax[i + 1], heights[i])
        ans = 0
        for i in range(1, n - 1):
            up = min(preMax[i - 1], sufMax[i + 1])
            bottom = heights[i]
            if up > bottom:
                ans += up - bottom       
        return ans