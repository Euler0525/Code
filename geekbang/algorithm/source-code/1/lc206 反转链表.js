/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
 var reverseList = function(head) {
    let now = head;
    let last = null;
    // 遍历
    while (now != null) {
        // 备份now.next
        let next = now.next;
        // 操作：now指向last
        now.next = last;
        // 往后移动
        last = now;
        now = next;
    }
    return last;
};