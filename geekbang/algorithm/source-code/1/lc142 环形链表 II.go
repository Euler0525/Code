// 这边和环形链表1的不同点在于，在判断出是环形链表1的基础上，还需要找出入环点
func detectCycle(head *ListNode) *ListNode {
	slow, fast := head, head
	for fast != nil {
		slow = slow.Next
		if fast.Next == nil {
			return nil
		}
		fast = fast.Next.Next
		// 快慢指针相遇，说明有环，需要进行进一步的操作
		// 这个操作前期可以记忆化背出来，即将p指针回到链表头，再分别p和慢指针分别往后遍历，最后相遇的点，就是入环点
		if fast == slow {
			p := head
			for p != slow {
				p = p.Next
				slow = slow.Next
			}
			return p
		}
	}
	return nil
}