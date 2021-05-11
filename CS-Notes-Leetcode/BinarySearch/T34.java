
// 2021.05.11
// Leetcode 第34题
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
package BinarySearch;

public class T34 {
    public static void main(String[] args) {
        T34 solution = new T34();
        int[] nums = { 5, 7, 7, 8, 8, 10 };
        int[] result = solution.searchRange(nums, 8);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public int[] searchRange(int[] nums, int target) {
        int first = findFirst(nums, target);
        int last = findFirst(nums, target + 1) - 1;
        if (first == nums.length || nums[first] != target) {
            return new int[] { -1, -1 };
        }
        return new int[] { first, Math.max(first, last) };
    }

    private int findFirst(int[] nums, int target) {
        int l = 0;
        // 注意 h 的初始值
        int h = nums.length;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (nums[m] >= target) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
}
