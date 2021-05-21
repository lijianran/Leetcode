
// 2021.05.21
// Leetcode 第 64 题
// https://leetcode-cn.com/problems/minimum-path-sum/description/
package DynamicProgramming;

public class T64 {
    public static void main(String[] args) {
        T64 solution = new T64();
        int[][] grid = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
        System.out.println(solution.minPathSum(grid));
    }

    public int minPathSum(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        int m = grid.length;
        int n = grid[0].length;
        int[] dp = new int[n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[j] = dp[j];
                } else if (i == 0) {
                    dp[j] = dp[j - 1];
                } else {
                    dp[j] = Math.min(dp[j], dp[j - 1]);
                }

                dp[j] += grid[i][j];
            }
        }

        return dp[n - 1];
    }
}
