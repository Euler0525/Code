/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    struct Info {
        Node* node;
        int depth;
    };

    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<Info> q;
        q.push({root, 0}); // {点，层数}
        while (!q.empty()) {
            Info now = q.front();
            q.pop();
            if (ans.size() <= now.depth) ans.push_back({});
            ans[now.depth].push_back(now.node->val);
            for (Node* child : now.node->children) {
                q.push({child, now.depth + 1});
            }
        }
        return ans;
        // queue = [{1, 0}, {3, 1}, {2, 1}, {4, 1}, {5, 2}, {6, 2}]
    }
};