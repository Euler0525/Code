class Solution:
    @staticmethod
    def countAsterisks(s: str) -> int:
        words = s.split("|")
        i = 0
        result = 0
        while i < len(words):
            result += sum(i == "*" for i in words[i])
            i += 2

        return result

# Pythonic
# class Solution:
#     @staticmethod
#     def countAsterisks(s: str) -> int:
#         return sum(t.count('*') for t in s.split('|')[::2])
