# include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0) return {""};
        if (n == 1) return {"()"};
        if (store.find(n) != store.end()) return store[n];
        vector<string> ans;

        // 加法原理
        for (int i = 1; i <= n; ++i)
        {
            vector<string> a = generateParenthesis(i - 1);
            vector<string> b = generateParenthesis(n - i);
            // 乘法原理
            for (const auto &a0: a)
            {
                for (const auto &b0: b)
                {
                    string tmp = "(" + a0 + ")" + b0;
                    ans.push_back(tmp);
                }
            }
        }
        store[n] = ans;
        return ans;
    }
private:
    unordered_map<int, vector<string>> store;
};
