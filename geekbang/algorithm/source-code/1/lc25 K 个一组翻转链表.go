func reverseKGroup(head *ListNode, k int) *ListNode {
	// 分成K个一组
	cur := head
	for i := 0; i < k; i++ {
		if cur == nil {
			return head
		}
		cur = cur.Next
	}
	// 调用反转链表模板
	newHead := reverse(head, cur)
	// 继续递归下一组
	head.Next = reverseKGroup(cur, k)
	return newHead
}

// 反转链表的模板，和原始题目唯一的不同是指定了起始节点和终止节点的范围
func reverse(start, end *ListNode) *ListNode {
	var pre *ListNode
	cur := start
	for cur != end {
		nxt := cur.Next
		cur.Next = pre
		pre = cur
		cur = nxt
	}
	return pre
}