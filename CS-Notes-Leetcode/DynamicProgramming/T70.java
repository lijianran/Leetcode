
// 2021.05.21
// Leetcode 第 70 题
// https://leetcode-cn.com/problems/climbing-stairs/description/
package DynamicProgramming;

public class T70 {
    public static void main(String[] args) {
        T70 solution = new T70();
        System.out.println(solution.climbStairs(2));
        System.out.println(solution.climbStairs(3));

    }

    public int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int pre1 = 1;
        int pre2 = 2;
        for (int i = 2; i < n; i++) {
            int cur = pre1 + pre2;
            pre1 = pre2;
            pre2 = cur;
        }

        return pre2;
    }
}
