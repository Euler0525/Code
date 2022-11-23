# include "iostream"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {}

    ListNode(int x) : val(x), next(nullptr)
    {}

    ListNode(int x, ListNode *next) : val(x), next(next)
    {}
};

// 1. 分组(向后k-1步到下一组); 开头为head, 结尾为end
// 2. 组内倒序;
// 3. 更新当前组与前一组和后一组的连接
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        auto *pre_head = new ListNode(-1, head);
        ListNode *last = pre_head;
        // 分组遍历
        while (head != nullptr)
        {
            ListNode *end = getEnd(head, k);
            if (end == nullptr)
            {
                break;
            }
            // 更新相邻组的连接
            ListNode *next_group_head = end->next;
            reverseList(head, next_group_head);
            last->next = end;

            cout << "一组反转后head: " << head->val << endl;
            cout << "一组反转后end: " << end->val << endl;
            cout << "new_group_head: " << next_group_head->val << endl;
            cout << "*************************" << endl;

            head->next = next_group_head;
            last = head;
            head = next_group_head;
        }
        return pre_head->next;
    }

    // 获取一个分组的结尾
    ListNode *getEnd(ListNode *head, int k)
    {
        // 分组
        while (head != nullptr)
        {
            --k;
            if (k == 0)
            {
                return head;
            }
            head = head->next;
        }

        return nullptr;
    }


    // 反转链表
    ListNode *reverseList(ListNode *head, ListNode *final)
    {
        ListNode *left;
        while (head != final)
        {
            ListNode *right = head->next;
            head->next = left;
            left = head;
            head = right;
        }

        cout << "函数内head: " << head->val << endl;

        return left;
    }
};


int main()
{
    auto *n5 = new ListNode(5, nullptr);
    auto *n4 = new ListNode(4, n5);
    auto *n3 = new ListNode(3, n4);
    auto *n2 = new ListNode(2, n3);
    auto *n1 = new ListNode(1, n2);
    Solution obj;
    obj.reverseKGroup(n1, 2);

    return 0;
}
