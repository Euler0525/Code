# include "queue"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {}
};

//// 深度优先搜索
//class Solution
//{
//public:
//    int rangeSumBST(TreeNode *root, int low, int high)
//    {
//        if (root == nullptr)
//        {
//            return 0;
//        }
//        if (root->val > high)
//        {
//            return rangeSumBST(root->left, low, high);
//        }
//        if (root->val < low)
//        {
//            return rangeSumBST(root->right, low, high);
//        }
//        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
//    }
//};

// 广度优先搜索
class Solution
{
public:
    static int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;
        queue<TreeNode *> q({root});
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node == nullptr)
            {
                continue;
            }
            if (node->val > high)
            {
                q.push(node->left);
            }
            else if (node->val < low)
            {
                q.push(node->right);
            }
            else
            {
                sum += node->val;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return sum;
    }
};
