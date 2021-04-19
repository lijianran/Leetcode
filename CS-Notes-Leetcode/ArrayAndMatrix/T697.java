
// 2021.04.19
// Leetcode 第697题
// https://leetcode-cn.com/problems/degree-of-an-array/
package ArrayAndMatrix;

import java.util.HashMap;
import java.util.Map;

public class T697 {
    public static void main(String[] args) {
        int[] nums = {1,2,2,3,1,4,2};
        T697 solution = new T697();
        System.out.println(solution.findShortestSubArray(nums));
    }

    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> numsCount = new HashMap<>();
        Map<Integer, Integer> numsLastIndex = new HashMap<>();
        Map<Integer, Integer> numsFirstIndex = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            numsCount.put(num, numsCount.getOrDefault(num, 0) + 1);
            numsLastIndex.put(num, i);
            if (!numsFirstIndex.containsKey(num)) {
                numsFirstIndex.put(num, i);
            }
        }

        int maxCount = 0;
        for (int num : nums) {
            maxCount = Math.max(maxCount, numsCount.get(num));
        }

        int result = nums.length;
        for (int num : nums) {
            int currentCount = numsCount.get(num);
            if (currentCount != maxCount) {
                continue;
            }
            result = Math.min(result, numsLastIndex.get(num) - numsFirstIndex.get(num) + 1);
        }

        return result;
    }
}
