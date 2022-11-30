func minDepth(root *TreeNode) int {
	// 递归终止条件1：如果当前节点是空，直接返回深度是0
	if root == nil {
		return 0
	}
	// 递归终止条件2：如果当前节点的左节点和右节点是空，直接返回深度是1
	if root.Left == nil && root.Right == nil {
		return 1
	}
	minD := math.MaxInt32
	// 当前节点的最小深度，取决于左节点和右节点最小深度的最小值+1
	if root.Left != nil {
		minD = min(minDepth(root.Left), minD)
	}
	if root.Right != nil {
		minD = min(minDepth(root.Right), minD)
	}
	return minD + 1
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}