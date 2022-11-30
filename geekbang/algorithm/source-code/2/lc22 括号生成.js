/**
 * @param {number} n
 * @return {string[]}
 */
// 分治解法
var store = {};
var generateParenthesis = function(n) {
    if (n == 0) return [""];
    if (n in store) return store[n]; // 记忆化
    let ans = [];
    for (let k = 1; k <= n; k++) { // 加法原理
        let A = generateParenthesis(k - 1);
        let B = generateParenthesis(n - k);
        // S=(A)B
        // 乘法原理
        for (let a of A)
            for (let b of B)
                ans.push("(" + a + ")" + b);
    }
    store[n] = ans;
    return ans;
};