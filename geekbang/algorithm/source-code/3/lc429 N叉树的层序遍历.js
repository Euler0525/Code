/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number[][]}
 */
 var levelOrder = function(root) {
    let q = [];
    let seq = [];
    if (root == null) return seq;
    q.push([root, 0]);
    while (q.length > 0) {
        let [node, depth] = q.shift();
        if (depth >= seq.length) seq.push([]);
        seq[depth].push(node.val);
        for (let child of node.children) {
            q.push([child, depth + 1]);
        }
    }
    return seq;
};