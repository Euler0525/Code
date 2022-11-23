// 核心思路，两两互换指针
func reverseList(head *ListNode) *ListNode {
	// 定义前置节点pre，也是一个在数组中不错的技巧，可以作为辅助的dummy空节点
	var pre *ListNode
	cur := head
	for cur != nil {
		// 开辟临时节点，记录当前节点cur的next指针（防止后面next指针发生变化后，丢失next指针的信息）
		nxt := cur.Next
		// 更新当前节点cur的next指针，指向pre节点
		cur.Next = pre
		// 当前节点变成前置节点pre
		pre = cur
		// 当前节点移动到下一个
		cur = nxt
	}
	return pre
}