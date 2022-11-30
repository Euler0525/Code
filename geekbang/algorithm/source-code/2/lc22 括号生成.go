// 首先还是明确使用回溯的思想解决这道题目
func generateParenthesis(n int) []string {
	res := []string{}

	// 一定要明确解决递归题目的关键，一个是递归模板，一个是递归状态里面，需要哪些状态变量
	// 本题中，状态变量可以左以下的抽象：
	// 1. 左括号还剩下几个：lRemain
	// 2. 右括号还剩下几个：rRemain
	// 3. 当前尝试路径：path
	var dfs func(lRemain int, rRemain int, path string)
	dfs = func(lRemain int, rRemain int, path string) {
		// 递归终止条件，当尝试的path长度等于2*n，就终止尝试本次递归
		if 2*n == len(path) {
			res = append(res, path)
			return
		}
		// 当前左括号还剩下，尝试左括号
		if lRemain > 0 {
			dfs(lRemain-1, rRemain, path+"(")
		}
		// 当前右括号比左括号多，尝试右括号，这里用了剪枝的技巧，保证右括号加入的合法性
		if lRemain < rRemain {
			dfs(lRemain, rRemain-1, path+")")
		}
	}

	dfs(n, n, "")
	return res
}