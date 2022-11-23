/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 链表的保护节点（提供入口，防止null异常）
        ListNode* entry = new ListNode();
        entry->next = head;
        ListNode* last = entry;
        while (head != nullptr) {
            // 分组
            ListNode* tail = getGroup(head, k);
            if (tail == nullptr) break;

            ListNode* nextHead = tail->next;

            // 当前组：head->...->tail
            // 下一组：nextHead->...

            // 组内反转
            reverseList(head, nextHead);

            // 当前组跟下一组、上一组的关系
            // 当前组：变成了tail->...->head
            last->next = tail;

            last = head;
            head = nextHead;
        }
        last->next = head;
        return entry->next;
    }

private:
    // 返回k个一组，组的尾部，null表示这组不够k个
    ListNode* getGroup(ListNode* head, int k) {
        while (head != nullptr) {
            k--;
            if (k == 0) return head;
            head = head->next;
        }
        return nullptr;
    }

    // 组的内部反转
    void reverseList(ListNode* head, ListNode* stop) {
        ListNode* now = head->next;
        ListNode* last = head;
        // 遍历
        while (now != stop) {
            // 备份now.next
            ListNode* next = now->next;
            // 操作：now指向last
            now->next = last;
            // 往后移动
            last = now;
            now = next;
        }
    }
};