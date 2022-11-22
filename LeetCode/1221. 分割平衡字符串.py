class Solution:
    def balancedStringSplit(self, s: str) -> int:
        cnt = 0
        flag = 0

        for i in s:
            if i == "L":
                flag += 1
            else:
                flag -= 1

            if flag == 0:
                cnt += 1

        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.balancedStringSplit("RLRRLLRLRL"))
