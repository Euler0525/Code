func insertIntoBST(root *TreeNode, val int) *TreeNode {
	// 特殊情况，如果当前的根节点是空，直接返回新增的节点
	if root == nil {
		return &TreeNode{Val: val}
	}
	// 用一个指针p来遍历访问BST
	p := root
	for p != nil {
		// 如果当前的值比p小，则取左边找
		if val < p.Val {
			if p.Left == nil {
				p.Left = &TreeNode{Val: val}
				break
			}
			p = p.Left
		} else {
			// 如果当前的值比p大，则去右边找
			if p.Right == nil {
				p.Right = &TreeNode{Val: val}
				break
			}
			p = p.Right
		}
	}
	return root
}