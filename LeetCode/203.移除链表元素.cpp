struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {}

    explicit ListNode(int x) : val(x), next(nullptr)
    {}

    ListNode(int x, ListNode *next) : val(x), next(next)
    {}
};

class Solution
{
public:
    static ListNode *removeElements(ListNode *head, int val)
    {
        auto pre_head = new ListNode(-1, head);
        auto curr = pre_head;
        while (curr->next != nullptr)
        {
            if (curr->next->val == val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }

        return pre_head->next;
    }
};
