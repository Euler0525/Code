var res [][]int

func permute(nums []int) [][]int {
	res = [][]int{}
	backTrack(nums, len(nums), []int{})
	return res
}
func backTrack(nums []int, numsLen int, path []int) {
	// 递归终止条件，将当前的尝试，持久化到结果集中
	if len(nums) == 0 {
		p := make([]int, len(path))
		copy(p, path)
		res = append(res, p)
	}
	for i := 0; i < numsLen; i++ {
		// 第i个数字
		cur := nums[i]
		// 将这个数字放到path路径中
		path = append(path, cur)
		// 使用go的切面技术，将这个已经取过的nums[i]，排除在nums之前按
		nums = append(nums[:i], nums[i+1:]...)
		// 继续递归回溯到下一层
		backTrack(nums, len(nums), path)
		// nums和path都需要还原现场
		nums = append(nums[:i], append([]int{cur}, nums[i:]...)...)
		path = path[:len(path)-1]

	}
}