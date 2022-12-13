/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        father = new HashMap<Integer, TreeNode>();
        calcFather(root);
        redNodes = new HashSet<Integer>();
        redNodes.add(root.val);
        while (p.val != root.val) {
            redNodes.add(p.val);
            p = father.get(p.val);
        }
        while (!redNodes.contains(q.val)) {
            q = father.get(q.val);
        }
        return q;
    }

    private void calcFather(TreeNode root) {
        if (root == null) return;
        if (root.left != null) {
            father.put(root.left.val, root);
            calcFather(root.left);
        }
        if (root.right != null) {
            father.put(root.right.val, root);
            calcFather(root.right);
        }
    }

    private Map<Integer, TreeNode> father;
    private Set<Integer> redNodes;
}