
// 2021.05.21
// Leetcode 第 62 题
// https://leetcode-cn.com/problems/unique-paths/
package DynamicProgramming;

import java.util.Arrays;

public class T62 {
    public static void main(String[] args) {
        T62 solution = new T62();
        System.out.println(solution.uniquePaths(3, 7));
    }

    public int uniquePaths(int m, int n) {
        int[] dp = new int[n];
        Arrays.fill(dp, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[n - 1];
    }
}
