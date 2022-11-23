class Solution:
    EXPLAIN = {"G": "G", "()": "o", "(al)": "al"}

    @staticmethod
    def interpret(command: str) -> str:
        words = str()
        i = 0
        while i < len(command):
            if command[i] == "G":
                words += "G"
                i += 1
            elif command[i] == "(" and command[i + 1] == ")":
                words += "o"
                i += 2
            else:
                words += "al"
                i += 4

        return words
