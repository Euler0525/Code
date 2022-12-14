/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int minDepth(TreeNode root) {
        // 不同于maxDepth的另一种写法
        // 也可以采用maxDepth的写法
        recur(root);
        return ans;
    }

    void recur(TreeNode node) {
        if (node == null) {
            ans = Math.min(ans, depth);
            return;
        }
        if (node.left == null && node.right == null) {
            ans = Math.min(ans, depth + 1);
            return;
        }
        depth++;
        if (node.left != null) recur(node.left);
        if (node.right != null) recur(node.right);
        depth--;
    }

    int depth = 0;
    int ans = 1 << 30;
}