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

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr) return {};
        q.push({root, 0});
        int flag = 0;
        while (!q.empty())
        {
            Info tmp = q.front();
            q.pop();
            if (tmp.depth > flag)
            {
                ans.push_back(layer);
                layer = {};
                ++flag;
            }
            layer.push_back(tmp.node->val);
            for (auto i = tmp.node->children.begin(); i!= tmp.node->children.end(); ++i)
            {
                q.push({*i, tmp.depth + 1});
            }
        }

        ans.push_back(layer);
        return ans;
    }
private:
    struct Info
    {
        Node *node;
        int depth;
    };
    queue<Info> q;
    vector<int> layer;
    vector<vector<int>> ans;
};
