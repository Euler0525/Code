func maxDepth(root *TreeNode) int {
	// 递归终止条件，空结点的深度为0
	if root == nil {
		return 0
	}
	// 递归和核心逻辑，当前层的最大高度，取决于左节点和右节点的最大高度的最大值+1
	return max(maxDepth(root.Left), maxDepth(root.Right)) + 1
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}