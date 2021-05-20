
// 2021.05.20
// Leetcode 第75题
// https://leetcode-cn.com/problems/sort-colors/comments/
// 三向切分快速排序
package Sort;

public class T75 {
    public static void main(String[] args) {
        int[] nums = { 2, 0, 2, 1, 1, 0 };
        T75 solution = new T75();
        solution.sortColors(nums);
        for (int i : nums) {
            System.out.println(i);
        }
    }

    public void sortColors(int[] nums) {
        int zero = -1;
        int one = 0;
        int two = nums.length;
        while (one < two) {
            if (nums[one] == 0) {
                swap(nums, ++zero, one++);
            } else if (nums[one] == 2) {
                swap(nums, --two, one);
            } else {
                ++one;
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
