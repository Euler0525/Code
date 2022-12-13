
func preorder(root *Node) (ans []int) {
	var dfs func(*Node)
	dfs = func(node *Node) {
		// 终止条件
		if node == nil {
			return
		}
		// 前序，先进行当前层的逻辑
		ans = append(ans, node.Val)
		for _, ch := range node.Children {
			// 递归
			dfs(ch)
		}
	}
	dfs(root)
	return
}