# 按位取值
class Solution:
    THOUSANDS = ["", "M", "MM", "MMM"]
    HUNDREDS = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
    TENS = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
    ONES = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]

    def intToRoman(self, num: int) -> str:
        return Solution.THOUSANDS[num // 1000] + \
               Solution.HUNDREDS[num % 1000 // 100] + \
               Solution.TENS[num % 100 // 10] + \
               Solution.ONES[num % 10]


# 打表模拟
class Solution:
    VALUES = [("M", 1000), ("CM", 900), ("D", 500), ("CD", 400), ("C", 100), ("XC", 90), ("L", 50), ("XL", 40),
              ("X", 10), ("IX", 9), ("V", 5), ("IV", 4), ("I", 1)]

    def intToRoman(self, num: int) -> str:
        roman = ""
        for key, value in self.VALUES:
            while num >= value:
                roman += key
                num -= value

        return roman
