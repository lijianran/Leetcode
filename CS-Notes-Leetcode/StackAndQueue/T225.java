
// 2021.04.20
// Leetcode 第225题
// https://leetcode-cn.com/problems/implement-stack-using-queues/description/
package StackAndQueue;

import java.util.LinkedList;
import java.util.Queue;

public class T225 {
    private Queue<Integer> queue;

    /** Initialize your data structure here. */
    public T225() {
        queue = new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        queue.add(x);
        int size = queue.size();
        while (size-- > 1) {
            queue.add(queue.poll());
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return queue.remove();
    }

    /** Get the top element. */
    public int top() {
        return queue.peek();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.isEmpty();
    }
}
