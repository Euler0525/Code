class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        wordsMap = new HashMap<>();
        int tot = 0; // words单词总长度
        for (String word : words) {
            tot += word.length();
            wordsMap.put(word, wordsMap.getOrDefault(word, 0) + 1);
        }
        List<Integer> ans = new ArrayList<Integer>();
        for (int i = 0; i + tot <= s.length(); i++) {
            // 看：s的从下标i开始的tot个字符构成的子串
            // 是不是由 words里的单词 按某种顺序串联形成的
            if (valid(s.substring(i, i + tot), words)) {
                ans.add(i);
            }
        }
        return ans;
    }

    boolean valid(String str, String[] words) {
        // 设k=words每个单词的长度
        // 把子串str每k个字符分成一个单词
        // 一共形成一个单词数组，看跟words是否一样即可
        int k = words[0].length();
        HashMap<String, Integer> h = new HashMap();
        for (int i = 0; i < str.length(); i += k) {
            String key = str.substring(i, i + k);
            h.put(key, h.getOrDefault(key, 0) + 1);
        }
        return h.equals(wordsMap);
    }

    HashMap<String, Integer> wordsMap;
};
// 请大家自行实现优化的解法