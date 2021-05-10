
// 2021.05.10
// Leetcode 第665题
// https://leetcode-cn.com/problems/can-place-flowers/description/
package Greed;

public class T665 {
    public static void main(String[] args) {
        int[] nums = { 4, 2, 3 };
        int[] nums2 = { 4, 2, 1 };

        T665 solution = new T665();
        System.out.println(solution.checkPossibility(nums));
        System.out.println(solution.checkPossibility(nums2));
    }

    public boolean checkPossibility(int[] nums) {
        int count = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] >= nums[i - 1]) {
                continue;
            }
            count++;
            if (i - 2 >= 0 && nums[i - 2] > nums[i]) {
                nums[i] = nums[i - 1];
            } else {
                nums[i - 1] = nums[i];
            }
        }

        return count <= 1;
    }
}
