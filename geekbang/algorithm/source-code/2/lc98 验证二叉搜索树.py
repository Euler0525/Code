# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.check(root, -2**31, 2**31-1)

    def check(self, root, rangeLeft, rangeRight):
        if not root:
            return True
        if root.val < rangeLeft or root.val > rangeRight:
            return False
        return self.check(root.left, rangeLeft, root.val - 1) and \
            self.check(root.right, root.val + 1, rangeRight)