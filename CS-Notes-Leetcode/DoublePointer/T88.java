
// 2021.04.21
// Leetcode 第88题
// https://leetcode-cn.com/problems/merge-sorted-array/description/
package DoublePointer;

public class T88 {
    public static void main(String[] args) {
        int[] nums1 = {1,2,3,0,0,0};
        int[] nums2 = {2,5,6};
        T88 solution = new T88();
        solution.merge(nums1, 3, nums2, nums2.length);
        for (int i : nums1) {
            System.out.println(i);
        }
    }

    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int index1 = m - 1;
        int index2 = n - 1;
        int index_merge = m + n - 1;

        while (index2 >= 0) {
            if (index1 < 0) {
                nums1[index_merge--] = nums2[index2--];
            } else if (index2 < 0) {
                nums1[index_merge--] = nums1[index1--];
            } else if (nums1[index1] > nums2[index2]) {
                nums1[index_merge--] = nums1[index1--];
            } else {
                nums1[index_merge--] = nums2[index2--];
            }
        }
    }
}
