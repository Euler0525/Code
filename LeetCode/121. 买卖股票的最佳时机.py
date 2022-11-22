# # 遍历
# class Solution:
#     @staticmethod
#     def maxProfit(prices: list[int]) -> int:
#         minprice = int(1e4)
#         profit = 0
#         for price in prices:
#             profit = max(price - minprice, profit)
#             minprice = min(price, minprice)
#
#         return profit

# 动态规划
class Solution:
    @staticmethod
    def maxProfit(prices: list[int]) -> int:
        res = [0] * len(prices)
        minprice = prices[0]

        for i in range(1, len(prices)):
            minprice = min(prices[i], minprice)
            res[i] = max(res[i - 1], prices[i] - minprice)

        return res[-1]
