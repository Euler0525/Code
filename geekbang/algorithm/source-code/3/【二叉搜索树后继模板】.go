func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {
	// 用来遍历二叉树的辅助节点
	curr := root
	// 结果节点
	ans := (*TreeNode)(nil)
	for curr != nil {
		// 第一种情况，当目前还没有找到val或者val没有右子树，则将比p大的里面最小的那个记录下来
		// if curr.Val > p.Val {
		// 	if ans == nil || ans.Val > p.Val {
		// 		ans = curr
		// 	}
		// }
		// 另一种一种情况，找到p节点
		if curr.Val == p.Val {
			// 如果有右子树，说明后继节点一定在右子树的最左边
			if curr.Right != nil {
				curr = curr.Right
				for curr.Left != nil {
					curr = curr.Left
				}
				return curr
			}
			break
		}
		if curr.Val > p.Val {
			// 当前答案还没有，或者答案有了，但是当前的节点的值虽然比value要大，但是比ans要小
			if ans == nil || ans.Val > curr.Val {
				ans = curr
			}
			// p比curr小，去左边
			curr = curr.Left
		} else {
			// p比curr大，去右边
			curr = curr.Right
		}
	}
	return ans
}