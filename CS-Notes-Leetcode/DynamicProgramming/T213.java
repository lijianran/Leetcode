
// 2021.05.21
// Leetcode 第 213 题
// https://leetcode-cn.com/problems/house-robber-ii/
package DynamicProgramming;

public class T213 {
    public static void main(String[] args) {
        T213 solution = new T213();
        int[] nums = { 2, 3, 2 };
        int[] nums2 = { 1, 2, 3, 1 };
        System.out.println(solution.rob(nums));
        System.out.println(solution.rob(nums2));

    }

    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        int n = nums.length;

        if (n == 1) {
            return nums[0];
        }

        return Math.max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }

    private int rob(int[] nums, int start, int end) {
        int pre2 = 0;
        int pre1 = 0;

        for (int i = start; i <= end; i++) {
            int cur = Math.max(pre2 + nums[i], pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }
}
