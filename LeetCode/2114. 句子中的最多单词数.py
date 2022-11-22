class Solution:
    def mostWordsFound(self, sentences: list[str]) -> int:
        max = 0
        for sentence in sentences:
            if max < len(sentence.split()):
                max = len(sentence.split())

        return max


if __name__ == "__main__":
    obj = Solution()
    print(obj.mostWordsFound(["alice and bob love leetcode", "i think so too", "this is great thanks very much"]))