class Solution:
    def largestLocal(self, grid: list[list[int]]) -> list[list[int]]:
        n = len(grid)
        result = [[0] * (n - 2) for _ in range(n - 2)]
        for i in range(n - 2):
            for j in range(n - 2):
                result[i][j] = max(grid[r][c] for r in range(i, i + 3) for c in range(j, j + 3))

        return result
