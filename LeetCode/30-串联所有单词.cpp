# include "bits/stdc++.h"

using namespace std;

/**
 * @algo
 * 1. 遍历words, 建立词频表
 * 2. 循环考察每一个i~i+length的字符串是否由words组成
 *
 * @func:
 * - 判断两个哈希表是否完全相同 equalHashMap(un_map * 2) -> bool
 * - 将字符串按长度单词长度断开, 建立频率哈希表genHashMap(string, int) -> un_map
 *
 * @var:
 * - ans(pub): 存储答案
 * - words_map(priv): words的词频表
 * - freq_map(local): 一个字符串拆分后的词频表
 */
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        int word_len = words[0].size();
        int words_len = words.size() * word_len;

        for (const string &word: words)
        {
            words_map[word] += 1;
        }

        for (int i = 0; i + words_len <= s.size(); ++i)
        {
            string tmp_str = s.substr(i, words_len);
            unordered_map<string, int> tmp_map = genHashMap(tmp_str, word_len);
            if (equalHashMap(tmp_map, words_map))
            {
                ans.push_back(i);
            }
        }

        return ans;
    }

private:
    unordered_map<string, int> words_map;

    unordered_map<string, int> genHashMap(string &str, int word_len)
    {
        unordered_map<string, int> result;
        int length = str.size();
        for (int i = 0; i + word_len <= length; i += word_len)
        {
            result[str.substr(i, word_len)] += 1;
        }

        return result;
    }

    // 判断两个哈希表是否完全相同
    bool equalHashMap(unordered_map<string, int> &a, unordered_map<string, int> &b)
    {
        for (const pair<string, int> str_and_int: a)
        {
            if (b[str_and_int.first] != str_and_int.second)
            {
                return false;
            }
        }
        for (const pair<string, int> str_and_int: b)
        {
            if (a[str_and_int.first] != str_and_int.second)
            {
                return false;
            }
        }

        return true;
    }
};
