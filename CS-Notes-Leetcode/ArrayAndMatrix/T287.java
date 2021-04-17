
// 2021.04.17
// Leetcode 第287题
// https://leetcode-cn.com/problems/find-the-duplicate-number/description/
package ArrayAndMatrix;

public class T287 {
    public static void main(String[] args) {
        T287 solution = new T287();
        int[] nums = { 1,1};
        System.out.println(solution.findDuplicate(nums));
    }

    public int findDuplicate(int[] nums) {
        int low = 1;
        int high = nums.length;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] <= mid) {
                    count++;
                }
            }
            if (count > mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
