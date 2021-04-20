
// 2021.04.20
// Leetcode 第232题
// https://leetcode-cn.com/problems/implement-queue-using-stacks/description/
package StackAndQueue;

import java.util.Stack;

public class T232 {
    public static void main(String[] args) {
        T232 myQueue = new T232();
        myQueue.push(1); // queue is: [1]
        myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
        int a = myQueue.peek(); // return 1
        int b = myQueue.pop(); // return 1, queue is [2]
        boolean c = myQueue.empty(); // return false

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);

    }

    private Stack<Integer> in = new Stack<>();
    private Stack<Integer> out = new Stack<>();

    /** Initialize your data structure here. */
    public T232() {

    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (out.isEmpty()) {
            while (!in.isEmpty()) {
                out.push(in.pop());
            }
        }
        return out.pop();
    }

    /** Get the front element. */
    public int peek() {
        if (out.isEmpty()) {
            while (!in.isEmpty()) {
                out.push(in.pop());
            }
        }
        return out.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return in.isEmpty() && out.isEmpty();
    }
}
