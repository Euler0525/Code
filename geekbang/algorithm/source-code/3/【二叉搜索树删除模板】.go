func deleteNode(root *TreeNode, key int) *TreeNode {
	// 如果根是空，则直接返回空
	if root == nil {
		return nil
	}
	// 找到了需要删除的节点
	if root.Val == key {
		// 递归终止条件1：左右子节点都是空，直接返回空即可
		if root.Left == nil && root.Right == nil {
			return nil
		}
		// 递归终止条件2：左孩子是空，右不空，直接将右孩子补位，返回给上一层继续处理
		if root.Left == nil && root.Right != nil {
			root = root.Right
			return root
		}
		// 递归终止条件3：左孩子不为空，右为空，左孩子补位，返回给上一层继续处理
		if root.Left != nil && root.Right == nil {
			root = root.Left
			return root
		}
		// 如果左右都不为空，找到右子树的最左节点
		next := root.Right
		for next.Left != nil {
			next = next.Left
		}
		// 在右子树里面，把这个最左节点删除
		root.Right = deleteNode(root.Right, next.Val)
		// 直接把这个删除的最左节点，赋值给当前根节点
		root.Val = next.Val
		return root
	}
	// 通用模板，如果当前节点比要删除的大，去左子树删
	if root.Val > key {
		root.Left = deleteNode(root.Left, key)
	}
	if root.Val < key {
		root.Right = deleteNode(root.Right, key)
	}
	return root
}