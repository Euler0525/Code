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
    ListNode* reverseList(ListNode* head) {
        ListNode* now = head;
        ListNode* last = nullptr;
        // 遍历
        while (now != nullptr) {
            // 备份now.next
            ListNode* next = now->next;
            // 操作：now指向last
            now->next = last;
            // 往后移动
            last = now;
            now = next;
        }
        return last;
    }
};