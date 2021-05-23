
// 2021.05.23
// Leetcode 第 413 题
// https://leetcode-cn.com/problems/arithmetic-slices/description/
package DynamicProgramming;

public class T413 {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4 };
        T413 solution = new T413();
        System.out.println(solution.numberOfArithmeticSlices(nums));
    }

    public int numberOfArithmeticSlices(int[] nums) {
        int[] diff = new int[nums.length];

        for (int i = 2; i < nums.length; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                diff[i] = diff[i - 1] + 1;
            }
        }

        int total = 0;
        for (int i : diff) {
            total += i;
        }

        return total;
    }
}
