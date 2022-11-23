# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    @staticmethod
    def getKthFromEnd(head: ListNode, k: int) -> ListNode:
        left = head
        right = head
        for _  in range(k):
            right=right.next
        while right:
            left = left.next
            right = right.next

        return left