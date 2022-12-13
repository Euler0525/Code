func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	// 递归终止条件1：如果当前节点是空，直接返回nil
	if root == nil {
		return nil
	}
	// 递归终止条件2：如果当前节点等于p或者q，直接找到返回root
	if root.Val == p.Val || root.Val == q.Val {
		return root
	}
	left := lowestCommonAncestor(root.Left, p, q)
	right := lowestCommonAncestor(root.Right, p, q)
	// 左右子节点找到了，直接返回root
	if left != nil && right != nil {
		return root
	}
	// 左边到头了，返回right
	if left == nil {
		return right
	}
	// 否则返回left
	return left
}