// 本程序支持加、减、乘、除、括号运算
/**
 * @param {string} s
 * @return {number}
 */
 var calculate = function(s) {

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

    var getRank = function(ch) {
        if (ch === '*' || ch === '/') return 2;
        if (ch === '+' || ch === '-') return 1;
        return 0;
    }

    s += " ";
    tokens = [];
    ops = [];
    let number = "";
    let needsZero = true;
    for (let ch of s) {
        if (ch >= '0' && ch <= '9') {
            number += ch;
            needsZero = false;
            continue;
        } else {
            if (number.length > 0) {
                tokens.push(number);
                number = "";
            }
        }
        if (ch == ' ') continue;
        if (ch == '(') {
            ops.push(ch);
            needsZero = true;
            continue;
        }
        if (ch == ')') {
            while (ops[ops.length - 1] != '(') {
                tokens.push(ops[ops.length - 1]); // 构造一个包含1个字符的字符串
                ops.pop();
            }
            ops.pop();
            needsZero = false;
            continue;
        }
        if ((ch == '+' || ch == '-') && needsZero) {
            tokens.push("0");
        }
        let currRank = getRank(ch);
        while (ops.length > 0 && getRank(ops[ops.length - 1]) >= currRank) {
            tokens.push(ops[ops.length - 1]); // 构造一个包含1个字符的字符串
            ops.pop();
        }
        ops.push(ch);
        needsZero = true;
    }
    while (ops.length > 0) {
        tokens.push(ops[ops.length - 1]);
        ops.pop();
    }
    return evalRPN(tokens);
/*
3+2*2
运算符栈：+ *
后缀表达式：3 2 2 * +

3+2-2
运算符栈：
后缀表达式：3 2 + 2 -
*/
};