/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
 var reverseKGroup = function(head, k) {

    // 返回k个一组，组的尾部，null表示这组不够k个
    var getGroup = function(head, k) {
        while (head != null) {
            k--;
            if (k == 0) return head;
            head = head.next;
        }
        return null;
    }

    // 组的内部反转
    var reverseList = function(head, stop) {
        let now = head.next;
        let last = head;
        // 遍历
        while (now != stop) {
            // 备份now.next
            let next = now.next;
            // 操作：now指向last
            now.next = last;
            // 往后移动
            last = now;
            now = next;
        }
    }


    // 链表的保护节点（提供入口，防止null异常）
    let entry = new ListNode();
    entry.next = head;
    let last = entry;
    while (head != null) {
        // 分组
        let tail = getGroup(head, k);
        if (tail == null) break;

        let nextHead = tail.next;

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
};
