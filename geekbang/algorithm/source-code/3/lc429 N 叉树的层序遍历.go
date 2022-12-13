func levelOrder(root *Node) (ans [][]int) {
	if root == nil {
		return
	}
	// 广度优先遍历，借助queue
	q := []*Node{root}
	for q != nil {
		level := []int{}
		tmp := q
		q = nil
		for _, node := range tmp {
			level = append(level, node.Val)
			q = append(q, node.Children...)
		}
		ans = append(ans, level)
	}
	return
}