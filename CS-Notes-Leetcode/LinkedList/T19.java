
// 2021.04.22
// Leetcode 第19题
// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
package LinkedList;

public class T19 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode cur = head;
        ListNode pre = head;
        for (int i = 0; i < n; i++) {
            cur = cur.next;
        }
        if (cur == null) {
            return head.next;
        }

        while (cur.next != null) {
            cur = cur.next;
            pre = pre.next;
        }

        pre.next = pre.next.next;
        return head;
    }
}
