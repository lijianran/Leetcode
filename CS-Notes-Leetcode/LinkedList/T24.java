
// 2021.04.22
// Leetcode 第24题
// https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
package LinkedList;

public class T24 {
    public ListNode swapPairs(ListNode head) {
        ListNode node = new ListNode(-1, head);
        ListNode pre = node;
        while (pre.next != null && pre.next.next != null){
            ListNode l1 = pre.next;
            ListNode l2 = l1.next;
            ListNode next = l2.next;

            l1.next = next;
            l2.next = l1;
            pre.next = l2;

            pre = l1;
        }
        
        return node.next;
    }
}
