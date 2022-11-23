class Solution
{
public:
    long long evalRPN(vector<string> &tokens)
    {
        for (const auto& token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                long long x = s.top();
                s.pop();
                long long y = s.top();
                s.pop();
                long long ans = calc(x, y, token);
                s.push(ans);
            }
            else
            {
                s.push(atoi(token.c_str()));  // 字符串转化为整数
            }
        }
        return s.top();
    }

    static long long calc(long long x, long long y, const string& op)
    {
        if (op == "+") return y + x;
        if (op == "-") return y - x;
        if (op == "*") return y * x;
        if (op == "/") return y / x;

        return 0;
    }
private:
    stack<long long> s;
};
