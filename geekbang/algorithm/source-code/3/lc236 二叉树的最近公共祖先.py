# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.father = {}
        self.calcFather(root)

        redNodes = {}
        redNodes[root.val] = True
        while p.val != root.val:
            redNodes[p.val] = True
            p = self.father[p.val]
        while q.val not in redNodes:
            q = self.father[q.val]
        return q   
    
    def calcFather(self, root):
        if not root:
            return
        if root.left:
            self.father[root.left.val] = root
            self.calcFather(root.left)
        if root.right:
            self.father[root.right.val] = root
            self.calcFather(root.right)