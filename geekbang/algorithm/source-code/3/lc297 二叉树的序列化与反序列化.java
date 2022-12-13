/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        List<String> seq = new ArrayList<String>();
        dfs(seq, root);
        return String.join(",", seq);
    }

    void dfs(List<String> seq, TreeNode root) {
        if (root == null) {
            seq.add("null");
            return;
        }
        seq.add(Integer.toString(root.val));
        dfs(seq, root.left);
        dfs(seq, root.right);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        seq = data.split(",");
        curr = 0;
        return restore();
    }

    TreeNode restore() {
        if (seq[curr].equals("null")) {
            curr++;
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(seq[curr]));
        curr++;
        root.left = restore();
        root.right = restore();
        return root;
    }

    String[] seq;
    int curr;
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));