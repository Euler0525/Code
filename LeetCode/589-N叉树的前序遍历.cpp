# include "bits/stdc++.h"

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node()
    {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// 迭代
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        if (root == nullptr) return {};
        nodes.push(root);
        while (!nodes.empty())
        {
            Node *tmp = nodes.top();
            nodes.pop();
            ans.push_back(tmp->val);
            if (tmp->children.size() == 0) continue;
            for (auto i = tmp->children.rbegin(); i != tmp->children.rend(); ++i)
            {
                nodes.push(*i);
            }
        }

        return ans;
    }
private:
    vector<int> ans;
    stack<Node *> nodes;  // 利用栈后进先出实现递归的作用
};

// 递归
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        dfs(root);

        return ans;
    }
private:
    vector<int> ans;
    void dfs(Node *root)
    {
        if (root == nullptr) return;
        ans.push_back(root->val);
        for (auto child : root->children)
        {
            preorder(child);
        }
    }
};
