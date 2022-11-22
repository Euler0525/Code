# 组合数
class Solution:
    def getRow(self, row_index: int) -> list[int]:
        row = list()
        for i in range(row_index + 1):
            row.append(self.comb(row_index, i))
        return row

    def comb(self, n, m):
        if n == 0 or m == 0:
            return 1
        return int(self.fact(n) / (self.fact(n - m) * self.fact(m)))

    def fact(self, n):
        if n == 0:
            return 1
        tmp = n
        for i in range(1, n):
            tmp *= i
        return tmp
