/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function(root) {
    // 不同于maxDepth的另一种写法
    // 也可以采用maxDepth的写法
    var depth = 0;
    var ans = 1 << 30;

    var recur = function(node) {
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
    
    recur(root);
    return ans;
};