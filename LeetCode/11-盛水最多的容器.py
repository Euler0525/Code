class Solution:
    def maxArea(self, height: list[int]) -> int:
        i = 0
        j = len(height) - 1
        max = 0

        while i < j:
            area = (j - i) * min(height[j], height[i])
            if area > max:
                max = area

            if height[i] >= height[j]:
                j -= 1
            else:
                i += 1

        return max
