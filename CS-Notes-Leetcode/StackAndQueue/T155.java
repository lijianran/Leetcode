
// 2021.04.20
// Leetcode 第155题
// https://leetcode-cn.com/problems/min-stack/
package StackAndQueue;

import java.util.Stack;

public class T155 {
    private Stack<Integer> dataStack;
    private Stack<Integer> minStack;
    private int min;

    /** initialize your data structure here. */
    public T155() {
        dataStack = new Stack<>();
        minStack = new Stack<>();
        min = Integer.MAX_VALUE;
    }

    public void push(int val) {
        dataStack.push(val);
        min = Math.min(min, val);
        minStack.push(min);
    }

    public void pop() {
        dataStack.pop();
        minStack.pop();
        min = minStack.isEmpty() ? Integer.MAX_VALUE : minStack.peek();
    }

    public int top() {
        return dataStack.peek();
    }

    public int getMin() {
        return minStack.peek();
    }
}
