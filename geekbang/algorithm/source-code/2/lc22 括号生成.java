class Solution {
    // 分治解法
    public List<String> generateParenthesis(int n) {
        if (store == null) store = new HashMap<>();
        if (n == 0) return Arrays.asList("");
        if (store.containsKey(n)) return store.get(n); // 记忆化
        List<String> ans = new ArrayList<String>();
        for (int k = 1; k <= n; k++) { // 加法原理
            List<String> A = generateParenthesis(k - 1);
            List<String> B = generateParenthesis(n - k);
            // S=(A)B
            // 乘法原理
            for (String a : A)
                for (String b : B)
                    ans.add("(" + a + ")" + b);
        }
        store.put(n, ans);
        return ans;
    }

    HashMap<Integer, List<String>> store;
}