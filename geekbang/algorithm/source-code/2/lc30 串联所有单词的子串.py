class Solution:
    def valid(self, str, words):
        # 设k=words每个单词的长度
        # 把子串str每k个字符分成一个单词
        # 一共形成一个单词数组，看跟words是否一样即可
        k = len(words[0])
        h = {}
        for i in range(0, len(str), k):
            key = str[i : i + k]
            h[key] = h.get(key, 0) + 1
        return h == self.wordsMap

    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        self.wordsMap = {}
    
        tot = 0 #/ words单词总长度
        for word in words:
            tot += len(word)
            self.wordsMap[word] = self.wordsMap.get(word, 0) + 1
        ans = []
        for i in range(0, len(s) - tot + 1):
            # 看：s的从下标i开始的tot个字符构成的子串
            # 是不是由 words里的单词 按某种顺序串联形成的
            if (self.valid(s[i : i + tot], words)):
                ans.append(i)
        return ans
# 请大家自行实现优化的解法