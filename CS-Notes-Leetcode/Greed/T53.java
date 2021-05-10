
// 2021.05.10
// Leetcode 第53题
// https://leetcode-cn.com/problems/maximum-subarray/
package Greed;

public class T53 {
    public static void main(String[] args) {
        int[] nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        int[] nums2 = { -1 };

        T53 solution = new T53();
        System.out.println(solution.maxSubArray(nums));
        System.out.println(solution.maxSubArray(nums2));

    }

    public int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int preSum = nums[0];
        int maxSum = preSum;
        for (int i = 1; i < nums.length; i++) {
            preSum = preSum > 0 ? preSum + nums[i] : nums[i];
            maxSum = Math.max(maxSum, preSum);
        }

        return maxSum;
    }
}
