import collections


class Solution:
    @staticmethod
    def isAnagram(s: str, t: str) -> bool:
        if collections.Counter(s) == collections.Counter(t):
            return True
        else:
            return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.isAnagram("rat", "car"))
