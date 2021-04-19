
// 2021.04.19
// Leetcode 第565题
// https://leetcode-cn.com/problems/array-nesting/comments/
package ArrayAndMatrix;

public class T565 {
    public static void main(String[] args) {
        int[] nums = {5,4,0,3,1,6,2};
        T565 solution = new T565();
        System.out.println(solution.arrayNesting(nums));
    }

    public int arrayNesting(int[] nums) {
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            for (int j = i; nums[j] != -1; ) {
                count++;
                int t = nums[j];
                nums[j] = -1;
                j = t;
            }
            max = Math.max(max, count);
        }

        return max;
    }
}
