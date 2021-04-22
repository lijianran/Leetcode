
// 2021.04.22
// Leetcode 第83题
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
package LinkedList;

public class T83 {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        if (head.val == head.next.val) {
            head = deleteDuplicates(head.next);
        } else {
            head.next = deleteDuplicates(head.next);
        }

        return head;
    }
}
