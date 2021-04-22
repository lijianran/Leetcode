
// 2021.04.22
// Leetcode 第328题
// https://leetcode-cn.com/problems/odd-even-linked-list/description/
package LinkedList;

public class T328 {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode pre = head;
        ListNode cur = head.next;
        ListNode behind = cur;
        while (cur != null && cur.next != null) {
            pre.next = pre.next.next;
            pre = pre.next;
            cur.next = cur.next.next;
            cur = cur.next;
        }
        pre.next = behind;
        return head;
    }
}
