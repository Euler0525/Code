# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.seq = []
        self.dfs(root)
        return self.seq

    def dfs(self, root):
        if not root:
            return
        self.dfs(root.left)
        self.seq.append(root.val)
        self.dfs(root.right)