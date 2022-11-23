/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        // 链表的保护节点（提供入口，防止null异常）
        ListNode entry = new ListNode();
        entry.next = head;
        ListNode last = entry;
        while (head != null) {
            // 分组
            ListNode tail = getGroup(head, k);
            if (tail == null) break;

            ListNode nextHead = tail.next;

            // 当前组：head->...->tail
            // 下一组：nextHead->...

            // 组内反转
            reverseList(head, nextHead);

            // 当前组跟下一组、上一组的关系
            // 当前组：变成了tail->...->head
            last.next = tail;

            last = head;
            head = nextHead;
        }
        last.next = head;
        return entry.next;
    }

    // 返回k个一组，组的尾部，null表示这组不够k个
    private ListNode getGroup(ListNode head, int k) {
        while (head != null) {
            k--;
            if (k == 0) return head;
            head = head.next;
        }
        return null;
    }

    // 组的内部反转
    private void reverseList(ListNode head, ListNode stop) {
        ListNode now = head.next;
        ListNode last = head;
        // 遍历
        while (now != stop) {
            // 备份now.next
            ListNode next = now.next;
            // 操作：now指向last
            now.next = last;
            // 往后移动
            last = now;
            now = next;
        }
    }
}