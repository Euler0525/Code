class Solution:
    @staticmethod
    def reverseLeftWords(s: str, n: int) -> str:
        return s[n:] + s[0: n]
