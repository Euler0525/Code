/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    var father = {};
    var calcFather = function(root) {
        if (root == null) return;
        if (root.left != null) {
            father[root.left.val] = root;
            calcFather(root.left);
        }
        if (root.right != null) {
            father[root.right.val] = root;
            calcFather(root.right);
        }
    }

    calcFather(root);

    var redNodes = {}
    redNodes[root.val] = true;
    while (p.val != root.val) {
        redNodes[p.val] = true;
        p = father[p.val];
    }
    while (!redNodes[q.val]) {
        q = father[q.val];
    }
    return q;   
};