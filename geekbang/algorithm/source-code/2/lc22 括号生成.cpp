class Solution {
public:
    // 分治解法
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        if (store.find(n) != store.end()) return store[n]; // 记忆化
        vector<string> ans;
        for (int k = 1; k <= n; k++) { // 加法原理
            vector<string> A = generateParenthesis(k - 1);
            vector<string> B = generateParenthesis(n - k);
            // S=(A)B
            // 乘法原理
            for (string& a : A)
                for (string& b : B)
                    ans.push_back("(" + a + ")" + b);
        }
        store[n] = ans;
        return ans;
    }

private:
    unordered_map<int, vector<string>> store;

    /*
    ((()))     
    (()())

    (())()
    ()(())

    ()()()    



    _ _|_ _ _ _  ()(())   ()()()
    _ _ _ _|_ _  (())()   ()()()


    S (A)B
    n  k-1 n-k


    k=1  (A)  A= 0对括号 ()   B=n-k=2对括号   ()()  (())
       ()()()  ()(())
    
    k=2  (A)  A=1对括号  (()) B=n-k=1对括号 ()
       (())()
    
    k=3  (A)  A=2对括号  (()()) ((()))   B=n-k=0对括号 空
        (()()) ((()))
      */
};