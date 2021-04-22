
// 2021.04.22
// Leetcode 第21题
// https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
package LinkedList;

public class T21 {
    public static void main(String[] args) {

    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode current = head;

        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                current.next = l1;
                current = current.next;
                l1 = l1.next;
            } else {
                current.next = l2;
                current = current.next;
                l2 = l2.next;
            }
        }

        if (l1 == null) {
            current.next = l2;
        } else {
            current.next = l1;
        }

        return head.next;
    }
}
