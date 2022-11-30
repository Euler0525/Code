# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        # 不同于maxDepth的另一种写法
        # 也可以采用maxDepth的写法
        self.depth = 0
        self.ans = 1 << 30
        self.recur(root)
        return self.ans

    def recur(self, node):
        if not node:
            self.ans = min(self.ans, self.depth)
            return
        if not node.left and not node.right:
            self.ans = min(self.ans, self.depth + 1)
            return
        self.depth += 1
        if node.left:
            self.recur(node.left)
        if node.right:
            self.recur(node.right)
        self.depth -= 1