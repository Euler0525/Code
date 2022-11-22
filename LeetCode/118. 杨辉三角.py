# 模拟
class Solution:
    @staticmethod
    def generate(num_rows: int) -> list[list[int]]:
        ret = list()
        for i in range(num_rows):
            row = list()
            for j in range(i + 1):
                if j == 0 or j == i:
                    row.append(1)
                else:
                    row.append(ret[i - 1][j] + ret[i - 1][j - 1])
            ret.append(row)

        return ret

# 错位加和
# class Solution:
#     def generate(self, num_rows: int) -> list[list[int]]:
#         ret = [[1]]
#         while len(ret) < num_rows:
#             row = [a + b for a, b in zip([0] + ret[-1], ret[-1] + [0])]
#             ret.append(row)
#         return ret
