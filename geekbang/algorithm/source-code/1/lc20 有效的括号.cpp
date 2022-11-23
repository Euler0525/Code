class Solution {
public:
    bool isValid(string s) {
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') a.push(ch);
            else {
                if (a.empty()) return false;
                if (ch == ')' && a.top() != '(') return false;
                if (ch == ']' && a.top() != '[') return false;
                if (ch == '}' && a.top() != '{') return false;
                a.pop();
            }
        }
        return a.empty();
    }

private:
    stack<char> a;
};