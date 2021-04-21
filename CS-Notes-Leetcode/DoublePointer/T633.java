
// 2021.04.21
// Leetcode 第633题
// https://leetcode-cn.com/problems/sum-of-square-numbers/description/
package DoublePointer;

public class T633 {
    public static void main(String[] args) {
        T633 solution = new T633();
        System.out.println(solution.judgeSquareSum(3));
    }

    public boolean judgeSquareSum(int c) {
        if (c < 0) {
            return false;
        }
        int small = 0;
        int big = (int) Math.sqrt(c);

        while (small <= big) {
            int sum = small * small + big * big;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                small++;
            } else {
                big--;
            }
        }
        return false;
    }
}
