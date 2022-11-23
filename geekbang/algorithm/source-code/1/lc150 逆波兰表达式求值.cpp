class Solution {
public:
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

private:
    stack<long long> s;

    long long calc(long long x, long long y, string& op) {
        if (op == "+") return x + y;
        if (op == "-") return x - y;
        if (op == "*") return x * y;
        if (op == "/") return x / y;
        return 0;
    }
};