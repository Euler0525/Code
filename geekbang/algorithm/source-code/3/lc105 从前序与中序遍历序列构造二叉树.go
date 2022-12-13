	// 前序遍历中的第一个节点就是根节点
	// 在中序遍历中定位根节点，然后确认左右子树的范围
	// 递归地构造左子树，并连接到根节点
	// 递归地构造右子树，并连接到根节点
	func buildTree(preorder []int, inorder []int) *TreeNode {
		// 递归终止条件
		if len(preorder) == 0 {
			return nil
		}
		// 当前层的处理逻辑，从先序数组中确认根节点
		root := &TreeNode{preorder[0], nil, nil}
		i := 0
		// 找到中序中根节点的位置
		for ; i < len(inorder); i++ {
			if inorder[i] == preorder[0] {
				break
			}
		}
		// 递归创建左子树
		root.Left = buildTree(preorder[1:len(inorder[:i])+1], inorder[:i])
		// 递归创建右子树
		root.Right = buildTree(preorder[len(inorder[:i])+1:], inorder[i+1:])
		return root
	}