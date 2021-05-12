
// 2021.05.12
// Leetcode 第153题
// https://leetcode-cn.com/problems/different-ways-to-add-parentheses/description/
package Divide;

import java.util.ArrayList;
import java.util.List;

public class T241 {
    public static void main(String[] args) {
        T241 solution = new T241();
        List<Integer> result = solution.diffWaysToCompute("2*3-4*5");
        for (Integer integer : result) {
            System.out.println(integer);
        }
    }

    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> ways = new ArrayList<>();
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                List<Integer> left = diffWaysToCompute(expression.substring(0, i));
                List<Integer> right = diffWaysToCompute(expression.substring(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        switch (c) {
                            case '+':
                                ways.add(l + r);
                                break;
                            case '-':
                                ways.add(l - r);
                                break;
                            case '*':
                                ways.add(l * r);
                                break;
                        }
                    }
                }
            }
        }

        if (ways.size() == 0) {
            ways.add(Integer.valueOf(expression));
        }
        return ways;
    }
}
