class Solution
{
public:
    static bool isValid(string &s)
    {
        unordered_map<char, char> pairs =
                {
                        {')', '('},
                        {']', '['},
                        {'}', '{'},
                };
        int n = static_cast<int>(s.size());
        stack<char> stk;
        if (n == 0 || n % 2 == 1)
        {
            return false;
        }

        for (auto c: s)
        {
            if (pairs.count(c) != 0 )
            {
                if (stk.empty() || stk.top() != pairs[c])
                {
                    return false;
                }
                stk.pop();
            }
            else
            {
                stk.push(c);
            }

        }

        return stk.empty();
    }
};


class Solution
{
public:
    bool isValid(string s)
    {
        for (auto ch: s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
            {
                stk.push(ch);
            }
            else
            {
                if (stk.empty()) return false;
                if (ch == ')' && stk.top() != '(') return false;
                if (ch == ']' && stk.top() != '[') return false;
                if (ch == '}' && stk.top() != '{') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }

private:
    stack<char> stk;
};
