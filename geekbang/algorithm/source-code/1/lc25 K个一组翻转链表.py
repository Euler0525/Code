# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        """
            Idea:
                1. Seperate all nodes to K groups
                    - For each group, the head node points to the end node of next groups 
                2. Reverse nodes inside of each group
                3. handle好头、尾node与下一组之间的关系

            Implementation:
                1. group内部之间的关系
                2. group headNode与上一组的关系
                3. group endNode与下一组的关系  
        """
        # 因为第一组的lastNode不存在，所以要建立个保护点（0）指向head，这样就避免了last为None的情况
        protect_node = ListNode(0, head)
        # last是作为上一组的最后一个点。
        last = protect_node
        while head != None:

            # thisGroupHead = ListNode(head.val, head.next) # Python is copy by value
            end = self.__getEnd(head, k)
            if (end==None): # Reached the ending group
                break
            # 保存next group head, 因为之后本组的新结尾（旧head）要跟下一组建立联系
            nextGroupHead = end.next

            # 处理head到end之间的k-1条边 ==> 反转之后end就是新的head
            # thisGroupHead = ListNode(head.val, head.next)
            self.__reverseList(head, end)

            # 让上一组跟本组的新head（旧end）建立联系
            last.next = end

            # 让本组的新结尾（旧head）要跟下一组建立联系
            head.next = nextGroupHead
            
            # 开始新的分组遍历
            last = head
            head = nextGroupHead
     
        return protect_node.next

    def __getEnd(self, head: ListNode, k: int) -> ListNode:
        # 从一个头开始，往回走k步，然后返回个endNode, 不足k步，就返回None
        # Becareful, There is k element in the group, but you only need to reverse k-1 edge
        while (head != None):
            # Put 'k-=1' first, so we can prevent the case for k==1
            k-=1
            if(k==0): 
                break
            head = head.next 
        return head

    # 不同于206. reverse list的是，这里不是把整个list反转过来，而是从head to end 这个group里的
    def __reverseList(self, head, end):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # If a group has one node
        if head == end: 
            return
            
        # 这里暂时不需要处理head与上一组之前的关系，所以advance pre, and head pointer
        pre = head
        head = head.next
        # 改每条边，所以需要访问整个链表
        while(head != end):
            next_node = head.next
            # 改一条边
            head.next = pre
            # Advance pre, and head
            pre = head
            head = next_node
        
        # EndNode points to last one
        end.next = pre

        # Now, head and end all poinst to the largest node of a group
        # return head, end