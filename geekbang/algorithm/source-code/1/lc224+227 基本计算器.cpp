// 本程序支持加、减、乘、除、括号运算
class Solution {
public:
    int calculate(string s) {
        s += " ";
        vector<string> tokens;
        string number = "";
        bool needsZero = true;
        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                number += ch;
                needsZero = false;
                continue;
            } else {
                if (!number.empty()) {
                    tokens.push_back(number);
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
                while (ops.top() != '(') {
                    tokens.push_back(string(1, ops.top())); // 构造一个包含1个字符的字符串
                    ops.pop();
                }
                ops.pop();
                needsZero = false;
                continue;
            }
            if ((ch == '+' || ch == '-') && needsZero) {
                tokens.push_back("0");
            }
            int currRank = getRank(ch);
            while (!ops.empty() && getRank(ops.top()) >= currRank) {
                tokens.push_back(string(1, ops.top())); // 构造一个包含1个字符的字符串
                ops.pop();
            }
            ops.push(ch);
            needsZero = true;
        }
        while (!ops.empty()) {
            tokens.push_back(string(1, ops.top()));
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
    }
private:
    stack<char> ops;

    int getRank(char ch) {
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return 0;
    }

    long long evalRPN(vector<string>& tokens) {
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long y = s.top();
                s.pop();
                long long x = s.top();
                s.pop();
                long long z = calc(x, y, token);
                s.push(z);
            } else {
                s.push(atoi(token.c_str())); // 字符串转化为整数
            }
        }
        return s.top();
    }

    stack<long long> s;

    long long calc(long long x, long long y, string& op) {
        if (op == "+") return x + y;
        if (op == "-") return x - y;
        if (op == "*") return x * y;
        if (op == "/") return x / y;
        return 0;
    }
};