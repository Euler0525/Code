# include "iostream"
# include "vector"
# include "stack"

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

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        if (root == nullptr)
        {
            return ret;
        }

        TreeNode *p1 = root, *p2 = nullptr;

        while (p1 != nullptr)
        {
            p2 = p1->left;
            if (p2 != nullptr)
            {
                while (p2->right != nullptr && p2->right != p1)
                {
                    p2 = p2->right;
                }
                if (p2->right == nullptr)
                {
                    ret.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                }
                else
                {
                    p2->right = nullptr;
                }
            }
            else
            {
                ret.emplace_back(p1->val);
            }
            p1 = p1->right;
        }

        return ret;
    }
};


// // Interation
// class Solution
// {
// public:
//     static vector<int> preorderTraversal(TreeNode *root)
//     {
//         vector<int> ret;
//         if (root == nullptr)
//         {
//             return ret;
//         }
//
//         stack<TreeNode *> stk;  // Temporarily store the root node
//         TreeNode *node = root;
//         while (!stk.empty() || node != nullptr)
//         {
//             while (node != nullptr)
//             {
//                 ret.emplace_back(node->val);  // emplace_back: Save space for creating elements
//                 stk.emplace(node);
//                 node = node->left;
//             }
//             node = stk.top();
//             stk.pop();
//             node = node->right;
//         }
//         return ret;
//     }
// };

//// Recursion
//class Solution
//{
//public:
//    void preorder(TreeNode *root, vector<int> &ret)
//    {
//        if (root == nullptr)
//        {
//            return;
//        }
//        ret.push_back(root->val);
//        preorder(root->left, ret);
//        preorder(root->right, ret);
//    }
//
//    vector<int> preorderTraversal(TreeNode *root)
//    {
//        vector<int> ret;
//        this->preorder(root, ret);
//
//        return ret;
//    }
//};
