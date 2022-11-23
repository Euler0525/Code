/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    var calc = function(x, y, op) {
        if (op === "+") return x + y;
        if (op === "-") return x - y;
        if (op === "*") return x * y;
        // (x/y)>>0是整除，正负数均可使用。Math.floor只能用于正数
        if (op === "/") return (x / y) >> 0;
        return 0;
    }

    let s = [];
    for (let token of tokens) {
        if (token === "+" || token === "-" || token === "*" || token === "/") {
            let y = s[s.length - 1];
            s.pop();
            let x = s[s.length - 1];
            s.pop();
            let z = calc(x, y, token);
            s.push(z);
        } else {
            s.push(parseInt(token)); // 字符串转化为整数
        }
    }
    return s[s.length - 1];
};