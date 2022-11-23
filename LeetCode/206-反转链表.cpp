# include "iostream"

using namespace std;

// head为链表的第一个节点
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


// 双指针
class Solution
{
public:
    static ListNode *reverseList(ListNode *head)
    {
        ListNode *left = nullptr, *right = head;
        while (right != nullptr)
        {
            ListNode *tmp = right->next;
            right->next = left;
            left = right;
            right = tmp;
        }

        return left;
    }
};


// 头插法
class Solution
{
public:
    static ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *prev_head = nullptr;
        ListNode *tmp = nullptr;

        while (head != nullptr)
        {
            tmp = head;
            head = head->next;
            tmp->next = prev_head;
            prev_head = tmp;
        }

        return prev_head;
    }
};


// 三指针
class Solution
{
public:
    static ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *left = nullptr;
        ListNode *mid = head;
        ListNode *right = mid->next;
        while (true)
        {
            mid->next = left;
            if (right == nullptr)
            {
                break;
            }
            left = mid;
            mid = right;
            right = right->next;
        }
        head = mid;
        return head;
    }
};


class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *left;
        while (head != nullptr)
        {
            ListNode *right = head->next;
            head->next = left;
            left = head;
            head = right;
        }

        return left;
    }
};
