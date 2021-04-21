
// 2021.04.21
// Leetcode 第167题
// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
package DoublePointer;

public class T167 {
    public static void main(String[] args) {
        int[] numbers = {2,7,11,15};
        T167 solution = new T167();
        int[] result = solution.twoSum(numbers, 9);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public int[] twoSum(int[] numbers, int target) {
        if (numbers == null) {
            return null;
        }
        int length = numbers.length;
        int small = 0;
        int big = length - 1;

        while (small < big) {
            int sum = numbers[small] + numbers[big];
            if (sum == target) {
                return new int[] { small + 1, big + 1 };
            } else if (sum < target) {
                small++;
            } else {
                big--;
            }
        }
        return null;
    }
}
