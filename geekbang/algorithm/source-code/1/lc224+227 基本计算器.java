// 本程序支持加、减、乘、除、括号运算
class Solution {
    public int calculate(String s) {
        s += " ";
        Stack<Character> ops = new Stack<>();
        List<String> tokens = new ArrayList<>();
        String number = "";
        boolean needsZero = true;
        for (char ch : s.toCharArray()) {
            if (ch >= '0' && ch <= '9') {
                number += ch;
                needsZero = false;
                continue;
            } else {
                if (!number.isEmpty()) {
                    tokens.add(number);
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
                while (ops.peek() != '(') {
                    tokens.add(Character.toString(ops.peek()));
                    ops.pop();
                }
                ops.pop();
                needsZero = false;
                continue;
            }
            if ((ch == '+' || ch == '-') && needsZero) {
                tokens.add("0");
            }
            int currRank = getRank(ch);
            while (!ops.empty() && getRank(ops.peek()) >= currRank) {
                tokens.add(Character.toString(ops.peek()));
                ops.pop();
            }
            ops.push(ch);
            needsZero = true;
        }
        while (!ops.empty()) {
            tokens.add(Character.toString(ops.peek()));
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

    int getRank(char ch) {
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return 0;
    }

    int evalRPN(List<String> tokens) {
        Stack<Long> s = new Stack<>();
        for (String token : tokens) {
            if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
                long y = s.peek();
                s.pop();
                long x = s.peek();
                s.pop();
                long z = calc(x, y, token);
                s.push(z);
            } else {
                s.push(Long.parseLong(token));
            }
        }
        return s.peek().intValue();
    }

    long calc(long x, long y, String op) {
        if (op.equals("+")) return x + y;
        if (op.equals("-")) return x - y;
        if (op.equals("*")) return x * y;
        if (op.equals("/")) return x / y;
        return 0;
    }
}