
// 2021.05.26
// Leetcode 第 416 题
// https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
package DynamicProgramming;

public class T416 {
    public static void main(String[] args) {
        T416 solution = new T416();
        int[] nums = { 1, 5, 11, 5 };
        System.out.println(solution.canPartition(nums));
    }

    public boolean canPartition(int[] nums) {
        if (nums == null || nums.length == 0) {
            return false;
        }
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }

        int W = sum / 2;
        boolean[] dp = new boolean[W + 1];
        dp[0] = true;
        for (int num : nums) {
            for (int i = W; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[W];
    }
}
