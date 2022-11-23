// 经典的使用快慢指针的思路来解题的题目
func hasCycle(head *ListNode) bool {
	// 养成习惯，一上来先对特殊情况做一下判断处理，可以提高性能
	if head == nil || head.Next == nil {
		return false
	}
	// 定义快慢指针
	slow, fast := head, head.Next
	for fast != slow {
		if fast == nil || fast.Next == nil {
			return false
		}
		slow = slow.Next
		fast = fast.Next.Next
	}
	// 一旦快慢指针相遇，直接返回true
	return true
}