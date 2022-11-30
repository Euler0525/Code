func subsets(nums []int) (ans [][]int) {
	// 辅助变量，用来暂存当前尝试的结果集
	set := []int{}
	var dfs func(int)
	// 递归函数，要符合递归模板
	dfs = func(cur int) {
		// 终止条件
		if cur == len(nums) {
			// 将当前这种可能的尝试数组，保存到ans结果集里面去
			ans = append(ans, append([]int(nil), set...))
			return
		}
		// 当前层的处理逻辑（选或不选），选择的情况
		set = append(set, nums[cur])
		dfs(cur + 1)
		// 清理现场，进行不选的递归尝试
		set = set[:len(set)-1]
		dfs(cur + 1)
	}
	dfs(0)
	return
}