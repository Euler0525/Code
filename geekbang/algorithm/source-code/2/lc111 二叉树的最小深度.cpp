/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 不同于maxDepth的另一种写法
        // 也可以采用maxDepth的写法
        recur(root);
        return ans;
    }
private:
    void recur(TreeNode* node) {
        if (node == nullptr) {
            ans = min(ans, depth);
            return;
        }
        if (!node->left && !node->right) {
            ans = min(ans, depth + 1);
            return;
        }
        depth++;
        if (node->left) recur(node->left);
        if (node->right) recur(node->right);
        depth--;
    }

    int depth = 0;
    int ans = 1 << 30;
};