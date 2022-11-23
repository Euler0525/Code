func removeDuplicates(nums []int) int {
	n := len(nums)
	// 特殊情况进行提效果，如果n小于1，直接返回0，可以提升性能和效率
	if n < 1 {
		return 0
	}
	// 定义快慢指针，快指针用来开辟数组，慢指针则用来记录真正需要存下来的元素
	slow := 0
	for fast := 1; fast < n; fast++ {
		// 如果当前快指针的元素不重复，记录到慢指针上
		if nums[fast] != nums[slow] {
			nums[slow+1] = nums[fast]
			slow++
		}
		// 如果重复，直接跳过，不记录
	}
	return slow + 1
}