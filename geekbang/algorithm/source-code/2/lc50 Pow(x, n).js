/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
// 分治解法
var myPow = function(x, n) {
    if (n == 0) return 1;
    if (n < 0) return 1.0 / myPow(x, -n);
    let temp = myPow(x, Math.floor(n / 2));
    let ans = temp * temp;
    if (n % 2 == 1) ans *= x;
    return ans;
};