// 像这种判断某元素成对出现的题目，栈是一个需要被第一时间想到的思路
func isValid(s string) bool {
	n := len(s)
	// 老生常谈，先判断特殊情况，比如这里，如果输入字符串的长度不是偶数，肯定不合法，直接返回false
	if n%2 == 1 {
		return false
	}
	// map字典
	pairs := map[byte]byte{
		')': '(',
		']': '[',
		'}': '{',
	}
	// 核心，定义一个栈
	stack := []byte{}
	for i := 0; i < n; i++ {
		// 如果当前pairs的keys里面包含当前字符（都是右侧符号），则进入判断逻辑，反之说明是左侧符号，直接入栈即可
		if pairs[s[i]] > 0 {
			// 如果说当前栈没有元素，或者和前一个左侧符号匹配不起来，直接返货错误
			if len(stack) == 0 || stack[len(stack)-1] != pairs[s[i]] {
				return false
			}
			// 如果可以匹配，弹栈，继续下一轮比较
			stack = stack[:len(stack)-1]
		} else {
			stack = append(stack, s[i])
		}
	}
	return len(stack) == 0
}