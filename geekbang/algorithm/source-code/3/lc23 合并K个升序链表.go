	func mergeKLists(lists []*ListNode) *ListNode {
		// 养成写链表题的好习惯，使用一个pre的虚拟节点，用来直接返回
		var pre, cur *ListNode
		// 统计lists中一共有多少个需要被合并的元素
		n := len(lists)
		// 遍历每一个元素
		for i := 0; i < n; i++ {
			if i == 0 {
				// 对于首个list，作为基线，后续的list合并到这个list之上即可
				pre = lists[i]
				continue
			}
			// 开始两辆合并
			cur = lists[i]
			pre = merge(pre, cur)
		}
		return pre
	}

	// 两两合并模板
	func merge(l1, l2 *ListNode) *ListNode {
		head := &ListNode{}
		cur := head
		for l1 != nil || l2 != nil {
			if l1 != nil && l2 != nil {
				if l1.Val < l2.Val {
					cur.Next = l1
					l1 = l1.Next
				} else {
					cur.Next = l2
					l2 = l2.Next
				}
				cur = cur.Next
			} else if l1 != nil {
				cur.Next = l1
				break
			} else {
				cur.Next = l2
				break
			}
		}
		return head.Next
	}