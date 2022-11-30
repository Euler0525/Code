/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
 var findSubstring = function(s, words) {
    var wordsMap = {};

    var valid = function(str, words) {
        // 设k=words每个单词的长度
        // 把子串str每k个字符分成一个单词
        // 一共形成一个单词数组，看跟words是否一样即可
        let k = words[0].length;
        let h = {};
        for (let i = 0; i < str.length; i += k) {
            let key = str.substring(i, i + k);
            h[key] = (h[key] || 0) + 1;
        }
        return _.isEqual(h, wordsMap);
    };
   
    let tot = 0; // words单词总长度
    for (let word of words) {
        tot += word.length;
        wordsMap[word] = (wordsMap[word] || 0) + 1;
    }
    let ans = [];
    for (let i = 0; i + tot <= s.length; i++) {
        // 看：s的从下标i开始的tot个字符构成的子串
        // 是不是由 words里的单词 按某种顺序串联形成的
        if (valid(s.substring(i, i + tot), words)) {
            ans.push(i);
        }
    }
    return ans;
};
// 请大家自行实现优化的解法