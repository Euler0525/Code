class Solution:
    def calc(self, x, y, op):
        if op == "+":
            return x + y
        if op == "-":
            return x - y
        if op == "*":
            return x * y
        if op == "/":
            return int(x / y)
        return 0

    def evalRPN(self, tokens: List[str]) -> int:
        s = []
        for token in tokens:
            if token == "+" or token == "-" or token == "*" or token == "/":
                y = s[-1]
                s.pop()
                x = s[-1]
                s.pop()
                z = self.calc(x, y, token)
                s.append(z)
            else:
                s.append(int(token))
        return s[-1]