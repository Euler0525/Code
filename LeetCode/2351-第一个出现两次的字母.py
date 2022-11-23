class Solution:
    @staticmethod
    def repeatedCharacter(s: str) -> str:
        tmp = list()
        for i in s:
            if i in tmp:
                return i
            else:
                tmp.append(i)
