# 本程序支持加、减、乘、除、括号运算
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

    def getRank(self, ch):
        if ch == '*' or ch == '/':
            return 2
        if ch == '+' or ch == '-':
            return 1
        return 0

    def calculate(self, s: str) -> int:
        s += " "
        tokens = []
        ops = []
        number = ""
        needsZero = True
        for ch in s:
            if ch >= '0' and ch <= '9':
                number += ch
                needsZero = False
                continue
            else:
                if len(number) > 0:
                    tokens.append(number)
                    number = ""
            if ch == ' ':
                continue
            if ch == '(':
                ops.append(ch)
                needsZero = True
                continue
            if ch == ')':
                while ops[-1] != '(':
                    tokens.append(ops[-1])
                    ops.pop()
                ops.pop()
                needsZero = False
                continue
            if (ch == '+' or ch == '-') and needsZero:
                tokens.append("0")
            currRank = self.getRank(ch)
            while len(ops) > 0 and self.getRank(ops[-1]) >= currRank:
                tokens.append(ops[-1])
                ops.pop()
            ops.append(ch)
            needsZero = True
        while len(ops) > 0:
            tokens.append(ops[-1])
            ops.pop()
        return self.evalRPN(tokens)