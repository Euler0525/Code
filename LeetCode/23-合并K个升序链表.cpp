# include "iostream"
# include "vector"

using namespace std;

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto head = new ListNode(-1, nullptr);
        ListNode *curr = head;
        for (auto & list : lists)
        {
            curr->next = this->mergeLists(head->next, list);
        }

        return head->next;
    }

    ListNode *mergeLists(ListNode *l1, ListNode *l2)
    {
        auto * head = new ListNode(-1, nullptr);
        ListNode *curr = head;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                curr = curr->next;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                curr = curr->next;
                l2 = l2->next;
            }
        }
        curr->next = l1 != nullptr ? l1 : l2;

        return head->next;
    }
};
