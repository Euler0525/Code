// 这里采用双指针的解法来解题
func trap(height []int) int {
	// 分别定义两个变量，来追踪当前列左边的最高高度，和当前列右边的最高高度
	leftMax, rightMax := 0, 0
	n := len(height)
	// 定义两个左右指针，分别从数组两头向中间推进
	left, right := 0, n-1
	ans := 0
	for left < right {
		// 计算左边的最大值
		leftMax = max(leftMax, height[left])
		// 计算右边的最大值
		rightMax = max(rightMax, height[right])
		// 比较左右，就取较小者，因为只有较小者才有可能蓄到水
		if height[left] > height[right] {
			// 核心公式，宽固定为1，高度取左右最大高度的较小者，减去当前高度
			ans += (rightMax - height[right])
			right--
		} else {
			ans += (leftMax - height[left])
			left++
		}
	}
	return ans
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}