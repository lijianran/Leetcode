
// 2021.04.20
// Leetcode 第20题
// https://leetcode-cn.com/problems/valid-parentheses/comments/
package StackAndQueue;

import java.util.Stack;

public class T20 {
    public static void main(String[] args) {
        T20 solution = new T20();
        System.out.println(solution.isValid("([)]"));
    }

    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                char top = stack.pop();
                boolean flag1 = c == ')' && top != '(';
                boolean flag2 = c == ']' && top != '[';
                boolean flag3 = c == '}' && top != '{';
                if (flag1 || flag2 || flag3) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}
