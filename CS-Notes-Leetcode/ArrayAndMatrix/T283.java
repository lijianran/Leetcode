
// 2021.04.15
// Leetcode 第283题
// https://leetcode-cn.com/problems/move-zeroes/description/
package ArrayAndMatrix;

class T283 {
    public static void main(String[] args) {
        int nums[] = { 0, 1, 0, 3, 12 };
        T283 solution = new T283();
        solution.moveZeroes(nums);

        for (int i : nums) {
            System.out.println(i);
        }
    }

    public void moveZeroes(int[] nums) {
        int idx = 0;
        for (int num : nums) {
            if (num != 0) {
                nums[idx++] = num;
            }
        }
        while (idx < nums.length) {
            nums[idx++] = 0;
        }
    }
}
