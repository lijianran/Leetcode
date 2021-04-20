
// 2021.04.20
// Leetcode 第739题
// https://leetcode-cn.com/problems/daily-temperatures/description/
package StackAndQueue;

import java.util.Stack;

public class T739 {
    public static void main(String[] args) {
        int[] temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
        T739 solution = new T739();
        int[] result = solution.dailyTemperatures(temperatures);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public int[] dailyTemperatures(int[] T) {
        int length = T.length;
        int[] dist = new int[length];
        Stack<Integer> stack = new Stack<>();
        for (int currentIndex = 0; currentIndex < length; currentIndex++) {
            while (!stack.isEmpty() && T[currentIndex] > T[stack.peek()]) {
                int preIndex = stack.pop();
                dist[preIndex] = currentIndex - preIndex;
            }
            stack.push(currentIndex);
        }
        return dist;
    }
}
