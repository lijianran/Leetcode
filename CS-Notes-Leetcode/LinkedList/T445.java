
// 2021.04.22
// Leetcode 第445题
// https://leetcode-cn.com/problems/add-two-numbers-ii/description/
package LinkedList;

import java.util.Stack;

public class T445 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> stack1 = buildStack(l1);
        Stack<Integer> stack2 = buildStack(l2);
        // 头指针
        ListNode head = new ListNode(-1);
        int carry = 0;
        while (!stack1.isEmpty() || !stack2.isEmpty() || carry != 0) {
            int x = stack1.isEmpty() ? 0 : stack1.pop();
            int y = stack2.isEmpty() ? 0 : stack2.pop();
            int sum = x + y + carry;
            ListNode node = new ListNode(sum % 10);
            // 头插法
            node.next = head.next;
            head.next = node;
            carry = sum / 10;
        }

        return head.next;
    }

    private Stack<Integer> buildStack(ListNode list) {
        Stack<Integer> stack = new Stack<>();
        while (list != null) {
            stack.push(list.val);
            list = list.next;
        }
        return stack;
    }
}
