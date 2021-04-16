
// 2021.04.16
// Leetcode 第485题
// https://leetcode-cn.com/problems/max-consecutive-ones/
package ArrayAndMatrix;

public class T485 {
    public static void main(String[] args) {
        T485 solution = new T485();

        int[] nums = { 1 };

        System.out.println(solution.findMaxConsecutiveOnes(nums));
    }

    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        int cur = 0;

        while (cur < nums.length) {
            if (nums[cur] == 0) {
                cur = cur + 1;
                continue;
            }
            int temp = 0;
            while (cur < nums.length && nums[cur] == 1) {
                temp = temp + 1;
                cur = cur + 1;
            }
            max = Math.max(temp, max);
        }

        return max;
    }
}
