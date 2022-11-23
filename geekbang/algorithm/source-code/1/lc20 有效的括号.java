class Solution {
    public boolean isValid(String s) {
        Stack<Character> a = new Stack<>();
        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '[' || ch == '{') a.push(ch);
            else {
                if (a.empty()) return false;
                if (ch == ')' && a.peek() != '(') return false;
                if (ch == ']' && a.peek() != '[') return false;
                if (ch == '}' && a.peek() != '{') return false;
                a.pop();
            }
        }
        return a.empty();
    }
}