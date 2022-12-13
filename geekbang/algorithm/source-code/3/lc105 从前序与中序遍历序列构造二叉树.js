/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
 var buildTree = function(preorder, inorder) {
  // 用 preorder[l1..r1] 和 inorder[l2..r2] 还原二叉树
  var build = function(l1, r1, l2, r2) {
      if (l1 > r1) return null;
      let root = new TreeNode(preorder[l1]);
      let mid = l2; // mid是root在inorder中的位置
      while (inorder[mid] != root.val) mid++;
      // l2~mid-1就是左子树中序
      // mid+1~r2就是右子树中序
      root.left = build(l1 + 1, l1 + (mid - l2), l2, mid - 1);
      root.right = build(l1 + (mid - l2) + 1, r1, mid + 1, r2);
      return root;
  }

  return build(0, preorder.length - 1, 0, inorder.length - 1);
};