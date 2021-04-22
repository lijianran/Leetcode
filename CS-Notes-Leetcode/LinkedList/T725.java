
// 2021.04.22
// Leetcode 第725题
// https://leetcode-cn.com/problems/split-linked-list-in-parts/description/
package LinkedList;

public class T725 {
    public ListNode[] splitListToParts(ListNode root, int k) {
        int length = 0;
        ListNode current = root;
        while (current != null) {
            length++;
            current = current.next;
        }
        int mod = length % k;
        int size = length / k;
        ListNode[] result = new ListNode[k];
        current = root;

        for (int i = 0; i < k && current != null; i++) {
            result[i] = current;
            int currentSize = size + ((mod-- > 0) ? 1 : 0);
            for (int j = 0; j < currentSize - 1; j++) {
                current = current.next;
            }

            ListNode next = current.next;
            current.next = null;
            current = next;
        }

        return result;
    }
}
