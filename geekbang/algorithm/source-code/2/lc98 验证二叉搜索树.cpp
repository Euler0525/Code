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
    bool isValidBST(TreeNode* root, long long l = -2147483648, long long r = 2147483647) {
        if (root == nullptr) return true;
        if (root->val < l || root->val > r) return false;
        return isValidBST(root->left, l, root->val - 1ll) && isValidBST(root->right, root->val + 1ll, r);
    }
};