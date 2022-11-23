/*
 * 这类借助栈去实现的题目，建议在纸上推演下全过程，就会比较清晰
 * 使用1-(2+3) = -4推演下具体的计算流程
 * 1）1，计算ans = 0+1 = 1
 * 2) - 取栈顶元素，转换操作符，sign=-1
 * 3）（， -1入栈
 * 4）2，计算ans = 1-2 = -1
 * 5) +, sign=-1（栈顶还是-1）
 * 6）3，计算ans = -1-3 = -4
 * 7) )，弹栈，将栈顶元素弹出
 */
func calculate(s string) (ans int) {
	ops := []int{1}
	sign := 1
	n := len(s)
	for i := 0; i < n; {
		switch s[i] {
		case ' ':
			i++
		case '+':
			sign = ops[len(ops)-1]
			i++
		case '-':
			sign = -ops[len(ops)-1]
			i++
		case '(':
			ops = append(ops, sign)
			i++
		case ')':
			ops = ops[:len(ops)-1]
			i++
		default:
			num := 0
			for ; i < n && '0' <= s[i] && s[i] <= '9'; i++ {
				num = num*10 + int(s[i]-'0')
			}
			ans += sign * num
		}
	}
	return
}