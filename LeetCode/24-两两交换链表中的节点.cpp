class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        auto *pre_head = new ListNode();
        pre_head->next = head->next;
        auto *last = new ListNode();
        last->next = head;
        while (head != nullptr)
        {
            ListNode *tmp = head->next->next;
            head->next->next = head;
            last->next = head->next;
            head->next = tmp;
            last = last->next->next;
            head = tmp;
            // 奇数
            if (head == nullptr || head->next == nullptr)
            {
                return pre_head->next;
            }
        }

        return pre_head->next;
    }
};
