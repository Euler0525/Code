struct ListNode
{
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr)
    {}
};

class Solution
{
public:
    static void deleteNode(ListNode *node)
    {
        // 冒充下一个节点，并把下一个节点删除
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
