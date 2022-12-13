/**
 * // Definition for a Node.
 * function Node(val, children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number[]}
 */
 var preorder = function(root) {
    let seq = [];
    if (root == null) return seq;
    let stack = [];
    stack.push(root);
    while (stack.length > 0) {
        let node = stack.pop();
        seq.push(node.val);
        for (let i = node.children.length - 1; i >= 0; i--) {
            stack.push(node.children[i]);
        }
    }
    return seq;
};