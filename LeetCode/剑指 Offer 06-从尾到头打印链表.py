# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# 递归
class Solution:
    def reversePrint(self, head: ListNode) -> list[int]:
        if head is None:
            return []

        return self.reversePrint(head.next) + [head.val]

# 栈
# class Solution:
#     def reversePrint(self, head: ListNode) -> list[int]:
#         stack = []
#         while head:
#             stack.append(head.val)
#             head = head.next
#         return stack[::-1]