/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
 var hasCycle = function(head) {
    let fast = head;
    while (fast != null && fast.next != null) {
        fast = fast.next.next;
        head = head.next;
        if (fast == head) return true;
    }
    return false;
};