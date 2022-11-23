class Solution {
    public int evalRPN(String[] tokens) {
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
                s.push(Long.parseLong(token)); // 字符串转化为整数
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