
// 2021.04.17
// Leetcode 第645题
// https://leetcode-cn.com/problems/set-mismatch/description/
package ArrayAndMatrix;

public class T645 {
    public static void main(String[] args) {
        T645 solution = new T645();

        int[] nums = { 3,2,2 };
        int[] result = solution.findErrorNums(nums);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public int[] findErrorNums(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums, i, nums[i] - 1);
            }
        }

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                return new int[] { nums[i], i + 1 };
            }
        }
        return null;
    }

    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
