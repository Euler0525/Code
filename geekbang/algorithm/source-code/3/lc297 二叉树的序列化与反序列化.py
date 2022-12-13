# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        self.seq = []
        self.dfs(self.seq, root)
        return ",".join(self.seq)

    def dfs(self, seq, root):
        if not root:
            self.seq.append("null")
            return
        self.seq.append(str(root.val))
        self.dfs(self.seq, root.left)
        self.dfs(self.seq, root.right)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        self.seq = data.split(",")
        self.curr = 0
        return self.restore()
        
    def restore(self):
        if self.seq[self.curr] == "null":
            self.curr += 1
            return None
        root = TreeNode(int(self.seq[self.curr]))
        self.curr += 1
        root.left = self.restore()
        root.right = self.restore()
        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))