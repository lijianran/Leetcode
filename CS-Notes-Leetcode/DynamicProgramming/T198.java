
// 2021.05.21
// Leetcode 第 198 题
// https://leetcode-cn.com/problems/house-robber/
package DynamicProgramming;

public class T198 {
    public static void main(String[] args) {
        T198 solution = new T198();
        int[] nums = { 1, 2, 3, 1 };
        int[] nums2 = { 2, 7, 9, 3, 1 };
        System.out.println(solution.rob(nums));
        System.out.println(solution.rob(nums2));

    }

    public int rob(int[] nums) {
        int pre2 = 0;
        int pre1 = 0;
        for (int i = 0; i < nums.length; i++) {
            int cur = Math.max(pre2 + nums[i], pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }
}
