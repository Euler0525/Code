import collections


# class Solution:
#     @staticmethod
#     def canConstruct(ransomNote: str, magazine: str) -> bool:
#         for i in ransomNote:
#             if i in magazine:
#                 magazine = magazine.replace(i, "", 1)
#                 print(magazine)
#             else:
#                 return False
#
#         return True


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False
        return not collections.Counter(ransomNote) - collections.Counter(magazine)


if __name__ == "__main__":
    obj = Solution()
    print(obj.canConstruct("aa", "aab"))
    print(collections.Counter("A")-collections.Counter("B"))