func moveZeroes(nums []int) {
	// 这类数组中进行顺序处理元素的操作，可以优先想到使用快慢指针去做
	if len(nums) == 0 {
		// 同样不要忘记可以针对特殊情况做处理，直接返回
		return
	}
	// 一样的思路，快指针先遍历，慢指针用来记录真正需要放数字的位置
	var slow int
	for fast := 0; fast < len(nums); fast++ {
		// 如果先驱节点fast不为0，交换和慢指针的位置
		if nums[fast] != 0 {
			nums[slow], nums[fast] = nums[fast], nums[slow]
			slow++
		}
		// 如果是0，不用管，继续遍历
	}
}