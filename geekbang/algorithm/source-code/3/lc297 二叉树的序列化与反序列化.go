type Codec struct{}

func Constructor() (_ Codec) {
	return
}

// 序列化
func (Codec) serialize(root *TreeNode) string {
	// 字符串构造器，方便构造返回字符串
	sb := &strings.Builder{}
	var dfs func(*TreeNode)
	dfs = func(node *TreeNode) {
		// 递归终止条件，如果当前节点时空，则更新字符串，并终止递归并返回
		if node == nil {
			sb.WriteString("null,")
			return
		}
		// 当前层的处理逻辑
		sb.WriteString(strconv.Itoa(node.Val))
		sb.WriteByte(',')
		// 递归访问左孩子节点和右边孩子节点
		dfs(node.Left)
		dfs(node.Right)
	}
	dfs(root)
	return sb.String()
}

func (Codec) deserialize(data string) *TreeNode {
	sp := strings.Split(data, ",")
	var build func() *TreeNode
	build = func() *TreeNode {
		// 递归终止条件
		if sp[0] == "null" {
			sp = sp[1:]
			return nil
		}
		// 将当前字符串复原为树节点
		val, _ := strconv.Atoi(sp[0])
		sp = sp[1:]
		return &TreeNode{val, build(), build()}
	}
	return build()
}