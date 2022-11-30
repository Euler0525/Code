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
 * @return {boolean}
 */
 var isValidBST = function(root) {
    var check = function(root, rangeLeft, rangeRight) {
        if (root == null) return true;
        if (root.val < rangeLeft || root.val > rangeRight) return false;
        return check(root.left, rangeLeft, root.val - 1) &&
            check(root.right, root.val + 1, rangeRight);
    }
    return check(root, -1e10, 1e10);
};