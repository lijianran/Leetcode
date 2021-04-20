
// 2021.04.20
// Leetcode 第503题
// https://leetcode-cn.com/problems/next-greater-element-ii/description/
package StackAndQueue;

import java.util.Arrays;
import java.util.Stack;

public class T503 {
    public static void main(String[] args) {
        int[] nums = {1,2,1};
        T503 solution = new T503();
        int[] result = solution.nextGreaterElements(nums);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public int[] nextGreaterElements(int[] nums) {
        int length = nums.length;
        int[] next = new int[length];
        Arrays.fill(next, -1);
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < length * 2; i++) {
            int num = nums[i % length];
            while (!stack.isEmpty() && num > nums[stack.peek()]) {
                next[stack.pop()] = num;
            }
            if (i < length) {
                stack.push(i);
            }
        }
        return next;
    }
}
