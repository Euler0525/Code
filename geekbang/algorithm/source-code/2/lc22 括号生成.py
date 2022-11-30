store = {}
class Solution:
    # 分治解法
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return [""]
        if n in store:
            return store[n] # 记忆化
        ans = []
        for k in range(1, n + 1): # 加法原理
            A = self.generateParenthesis(k - 1)
            B = self.generateParenthesis(n - k)
            # S=(A)B
            # 乘法原理
            for a in A:
                for b in B:
                    ans.append("(" + a + ")" + b)
        store[n] = ans
        return ans