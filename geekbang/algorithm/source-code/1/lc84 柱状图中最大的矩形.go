// 朴素思想，从每根柱子往两边扩展，找到第一个比它矮的柱子
// 引申到单调栈的情况，左边直接走到头，右边终止了（复杂度仅为O（n））
// 碰到右边破坏性的矮柱子，直接把当前柱子的答案更新完毕后，删除高度信息，只保留宽度信息给后续即可（删除复杂度也是O(n)）
// 操作只在尾部发生，就自然推演出，可以使用栈这个数据结构
// 也就是说，破坏单调性，会触发计算
func largestRectangleArea(heights []int) int {
	area := 0
	// 单调栈
	stack := make([]int, 0)
	stack = append(stack, -1)

	// 寻找每一个height
	for i, height := range heights {
		// 如果当前柱子的height破坏的单调栈的单调性，出发删除和计算逻辑
		for stack[len(stack)-1] != -1 && height < heights[stack[len(stack)-1]] {
			// 获取栈顶高度
			high := heights[stack[len(stack)-1]]
			// 弹出栈顶元素
			stack = stack[:len(stack)-1]

			//  (right-left-1) 是从当前第i-1个位置到栈顶元素的累计宽度，和high乘积，及是当前弹出这个柱子的结果
			left, right := stack[len(stack)-1], i
			area = max(area, (right-left-1)*high)
		}
		// 整理完毕后，将当前柱子i加入单调栈
		stack = append(stack, i)
	}

	// 最后通过-1这个最小值，破坏剩余单调栈的单调性，来把前面的所有单调柱子弹出，计算其最大的面积
	for stack[len(stack)-1] != -1 {
		high := heights[stack[len(stack)-1]]
		stack = stack[:len(stack)-1]

		left, right := stack[len(stack)-1], len(heights)
		area = max(area, (right-left-1)*high)
	}
	return area
}

func max(x int, y int) int {
	if x < y {
		return y
	}
	return x
}