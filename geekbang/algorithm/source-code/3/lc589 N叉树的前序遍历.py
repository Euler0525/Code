"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        q = collections.deque([])
        seq = []
        if not root:
            return seq
        q.append([root, 0])
        while len(q) > 0:
            # Don't use list.pop(0), which is O(N)
            # deque.popleft() is O(1)
            node, depth = q.popleft()
            if depth >= len(seq):
                seq.append([])
            seq[depth].append(node.val)
            for child in node.children:
                q.append([child, depth + 1])
        return seq