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
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *a = headA, *b = headB;
        while (a != b)
        {
            a = a != nullptr ? a->next : headB;
            b = b != nullptr ? b->next : headA;
        }

        return a;
    }
};
