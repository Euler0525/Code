// 思路和组合类似，区别在于终止条件多了限制
func combine(n int, k int) (ans [][]int) {
	temp := []int{}
	var dfs func(int)
	dfs = func(cur int) {
		// 剪枝：剪掉不可能的部分，提高程序的性能
		if len(temp)+(n-cur+1) < k {
			return
		}
		// 递归终止条件，组合场景想的限制
		if len(temp) == k {
			comb := make([]int, k)
			copy(comb, temp)
			ans = append(ans, comb)
			return
		}
		// 当前层处理逻辑，和子集类似，选或者不选
		temp = append(temp, cur)
		dfs(cur + 1)
		// 清理现场，进行另一个分支的选择
		temp = temp[:len(temp)-1]
		dfs(cur + 1)
	}
	dfs(1)
	return
}