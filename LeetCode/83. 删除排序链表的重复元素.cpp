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
    static ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *pointer = head;
        while (pointer != nullptr)
        {
            while ( pointer->next != nullptr && pointer->val == pointer->next->val)
            {
                pointer->next = pointer->next->next;
            }
            pointer = pointer->next;
        }

        return head;
    }
};
