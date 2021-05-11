
// 2021.05.11
// Leetcode 第540题
// https://leetcode-cn.com/problems/single-element-in-a-sorted-array/description/
package BinarySearch;

public class T540 {
    public static void main(String[] args) {
        T540 solution = new T540();
        int[] nums = { 1, 1, 2, 3, 3, 4, 4, 8, 8 };
        int[] nums2 = { 3, 3, 7, 7, 10, 11, 11 };

        System.out.println(solution.singleNonDuplicate(nums));
        System.out.println(solution.singleNonDuplicate(nums2));

    }

    public int singleNonDuplicate(int[] nums) {
        int l = 0;
        int h = nums.length - 1;

        while (l < h) {
            int m = l + (h - l) / 2;
            if (m % 2 == 1) {
                m--;
            }
            if (nums[m] == nums[m + 1]) {
                l = m + 2;
            } else {
                h = m;
            }
        }
        return nums[l];
    }
}
