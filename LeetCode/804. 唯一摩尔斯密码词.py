class Solution:
    @staticmethod
    def uniqueMorseRepresentations(words: list[str]) -> int:
        LIST = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
        word = str()
        ans = list()
        for i in words:
            for j in i:
                word += LIST[ord(j) - ord("a")]
            ans.append(word)
            word = str()

        return len(set(ans))


# 简化代码
# MORSE = \
#     [
#         ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
#         "....", "..", ".---", "-.-", ".-..", "--", "-.",
#         "---", ".--.", "--.-", ".-.", "...", "-", "..-",
#         "...-", ".--", "-..-", "-.--", "--.."
#     ]
#
# class Solution:
#     def uniqueMorseRepresentations(self, words: list[str]) -> int:
#         return len(set("".join(MORSE[ord(ch) - ord('a')] for ch in word) for word in words))
