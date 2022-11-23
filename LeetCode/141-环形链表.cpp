# include "iostream"
# include "unordered_set"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr)
    {}
};
//// 哈希表
//class Solution
//{
//public:
//    static bool hasCycle(ListNode *head)
//    {
//        unordered_set<ListNode*> hash_table;
//
//        while(head != nullptr)
//        {
//            if (hash_table.count(head))
//            {
//                return true;
//            }
//            hash_table.insert(head);
//            head = head->next;
//        }
//
//        return false;
//    }
//};

// 龟兔赛跑
class Solution
{
public:
    static bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};
