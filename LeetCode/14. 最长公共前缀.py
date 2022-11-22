class Solution(object):
    def longestCommonPrefix(self, strs: list[str]) -> str:
        if not strs:
            return ""

        longest_prefix = strs[0]
        for j in range(1, len(strs)):
            longest_prefix = self.commonPrefix(longest_prefix, strs[j])

        if longest_prefix:
            return longest_prefix
        else:
            return ""

    def commonPrefix(self, str_1, str_2):
        length = min(len(str_1), len(str_2))
        index = 0
        while index < length and str_1[index] == str_2[index]:
            index += 1

        return str_1[:index]
