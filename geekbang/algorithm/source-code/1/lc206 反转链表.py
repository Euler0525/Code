# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        now = head
        last = None
        # 遍历
        while now:
            # 备份now.next
            next = now.next
            # 操作：now指向last
            now.next = last
            # 往后移动
            last = now
            now = next
        return last