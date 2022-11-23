# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = current = ListNode()
        carry = 0
        while l1 or l2 or carry:
            carry += (l1.val if l1 else 0) + (l2.val if l2 else 0)
            current.next = ListNode(carry % 10)
            carry //= 10
            current = current.next
            l1, l2 = (l1.next if l1 else None), (l2.next if l2 else None)

        return head.next
