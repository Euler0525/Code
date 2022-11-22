class Solution:
    TABLE = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

    def romanToInt(self, s: str) -> int:
        result = 0
        length = len(s)
        for i, ch in enumerate(s):
            num = self.TABLE[ch]
            if i < length - 1 and num < self.TABLE[s[i + 1]]:
                result -= num
            else:
                result += num

        return result
