
// 2021.04.22
// Leetcode 第106题
// https://leetcode-cn.com/problems/reverse-linked-list/description/
package LinkedList;

public class T206 {
    public static void main(String[] args) {

    }

    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode next = head.next;
        ListNode newHead = reverseList(next);

        next.next = head;
        head.next = null;

        return newHead;
    }
}
