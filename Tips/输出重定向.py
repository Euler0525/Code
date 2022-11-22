import sys

# 输出重定向
f = open("log_file.txt", "w")
sys.stdout = f

print("Hello World")

f.close()

# 重定向恢复
sys.stdout = sys.__stdout__
