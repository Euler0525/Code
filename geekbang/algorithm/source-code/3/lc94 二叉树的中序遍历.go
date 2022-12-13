func inorderTraversal(root *TreeNode) (res []int) {
	var inorder func(node *TreeNode)
	inorder = func(node *TreeNode) {
		// 终止函数
		if node == nil {
			return
		}
		// 递归逻辑
		inorder(node.Left)
		// 当前层处理
		res = append(res, node.Val)
		// 递归逻辑
		inorder(node.Right)
	}
	inorder(root)
	return
}