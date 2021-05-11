
// 2021.05.11
// Leetcode 第153题
// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
package BinarySearch;

public class T153 {
    public static void main(String[] args) {
        T153 solution = new T153();
        int[] nums = { 3, 4, 5, 1, 2 };
        int[] nums2 = { 4, 5, 6, 7, 0, 1, 2 };

        System.out.println(solution.findMin(nums));
        System.out.println(solution.findMin(nums2));
    }

    public int findMin(int[] nums) {
        int l = 0;
        int h = nums.length - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (nums[m] <= nums[h]) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return nums[l];
    }
}
