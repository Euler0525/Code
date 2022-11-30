func invertTree(root *TreeNode) *TreeNode {
	// 递归终止条件
	if root == nil {
		return nil
	}
	// 这边有些小变化，先递归，再解决当前层的问题，需要灵活变换
	left := invertTree(root.Left)
	right := invertTree(root.Right)
	// 交换当前层的左右子节点
	root.Left = right
	root.Right = left
	return root
}