import collections
import copy


# class Solution:
#     @staticmethod
#     def firstUniqChar(s: str) -> int:
#         if len(s) == 1:
#             return 0
#
#         tmp = copy.copy(s)
#         for i in range(len(s)):
#             if s[i] not in tmp[0:i] and s[i] not in tmp[i + 1:]:
#                 return i
#
#         return -1

# 哈希表
class Solution:
    @staticmethod
    def firstUniqChar(s: str) -> int:
        frequency = collections.Counter(s)
        for i, ch in enumerate(s):
            if frequency[ch] == 1:
                return i
        return -1
# Counter() -> dict: 统计字符出现次数