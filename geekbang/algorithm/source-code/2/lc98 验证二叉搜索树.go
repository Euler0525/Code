func isValidBST(root *TreeNode) bool {
	return helper(root, math.MinInt64, math.MaxInt64)
}

func helper(root *TreeNode, lower, upper int) bool {
	// 递归终止条件1
	if root == nil {
		return true
	}
	// 递归终止条件2，吐过当前节点违反BST的规则，即左子节点必须比当前节点小并且右子节点必须比当前节点大，直接返回false
	if root.Val <= lower || root.Val >= upper {
		return false
	}
	// 这里的当前层处理逻辑比较简单，直接基于递归的结果，做逻辑与的操作，向上返回即可
	return helper(root.Left, lower, root.Val) && helper(root.Right, root.Val, upper)
	// 没有全局变量，不需要清理现场
}