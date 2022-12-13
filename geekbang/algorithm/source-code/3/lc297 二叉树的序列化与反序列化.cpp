/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs(seq, root);
        string ans;
        for (int i = 0; i < seq.size(); i++) {
            if (i > 0) ans.append(",");
            ans.append(seq[i]);
        }
        return ans;
    }

    void dfs(vector<string>& seq, TreeNode* root) {
        if (root == nullptr) {
            seq.push_back("null");
            return;
        }
        seq.push_back(to_string(root->val));
        dfs(seq, root->left);
        dfs(seq, root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        seq.clear();
        string temp;
        for (char ch : data) {
            if (ch == ',') seq.push_back(temp), temp.clear();
            else temp.push_back(ch);
        }
        seq.push_back(temp);
        curr = 0;
        return restore();
    }

    TreeNode* restore() {
        if (seq[curr] == "null") {
            curr++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(seq[curr]));
        curr++;
        root->left = restore();
        root->right = restore();
        return root;
    }

    vector<string> seq;
    int curr;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));