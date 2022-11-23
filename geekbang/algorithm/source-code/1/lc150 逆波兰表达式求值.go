// 逆波兰式，后面熟练了要马上联想到可以使用栈的方式去实现
func evalRPN(tokens []string) int {
	stack := []int{}
	for _, token := range tokens {
		// 这里用了个小技巧，将当前的元素转换成数字，并且借助这个转换是否成功，来判断当前的元素是否是数字
		val, err := strconv.Atoi(token)
		if err == nil {
			// 如果是数字，直接加入栈即可
			stack = append(stack, val)
		} else {
			// 如果不是数字，需要出栈之前的两个元素，来做判断
			num1, num2 := stack[len(stack)-2], stack[len(stack)-1]
			stack = stack[:len(stack)-2]
			// 针对不同的计算符，制定不同的策略
			switch token {
			case "+":
				stack = append(stack, num1+num2)
			case "-":
				stack = append(stack, num1-num2)
			case "*":
				stack = append(stack, num1*num2)
			default:
				stack = append(stack, num1/num2)
			}
		}
	}
	return stack[0]
}