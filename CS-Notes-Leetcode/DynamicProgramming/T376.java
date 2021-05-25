
// 2021.05.25
// Leetcode 第 376 题
// https://leetcode-cn.com/problems/wiggle-subsequence/description/
package DynamicProgramming;

public class T376 {
    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;
        if (nums == null || n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2 && nums[0] != nums[1]) {
            return 2;
        }

        int down = 1;
        int up = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            }
            if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }
        return Math.max(up, down);
    }
}
