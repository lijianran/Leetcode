
// 2021.05.23
// Leetcode 第 303 题
// https://leetcode-cn.com/problems/range-sum-query-immutable/description/
package DynamicProgramming;

public class T303 {
    private int[] sums;

    public T303(int[] nums) {
        sums = new int[nums.length + 1];
        for (int i = 1; i <= nums.length; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
    }
    
    public int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
}
