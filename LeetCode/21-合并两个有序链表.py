# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 递归
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        elif l2 is None:
            return l1
        elif l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2
# 迭代
# class Solution:
#     def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
#         head = current = ListNode()
#         while l1 and l2:
#             if l1.val <= l2.val:
#                 current.next = l1
#                 l1 = l1.next
#             else:
#                 current.next = l2
#                 l2 = l2.next
#             current = current.next
#         current.next = l1 if l1 else l2
#
#         return head.next
