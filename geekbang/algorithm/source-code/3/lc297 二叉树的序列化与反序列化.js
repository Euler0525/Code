/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    let seq = [];

    var dfs = function(seq, root) {
        if (root == null) {
            seq.push("null");
            return;
        }
        seq.push(root.val.toString());
        dfs(seq, root.left);
        dfs(seq, root.right);
    }

    dfs(seq, root);
    return seq.join(",");
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    let seq = data.split(",");
    let curr = 0;

    var restore = function() {
        if (seq[curr] == "null") {
            curr++;
            return null;
        }
        let root = new TreeNode(parseInt(seq[curr]));
        curr++;
        root.left = restore();
        root.right = restore();
        return root;
    }

    return restore();
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */