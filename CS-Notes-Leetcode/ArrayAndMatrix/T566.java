
// 2021.04.15
// Leetcode 第566题
// https://leetcode-cn.com/problems/reshape-the-matrix/description/
package ArrayAndMatrix;

public class T566 {
    public static void main(String[] args) {
        int[][] nums = { { 1, 2 }, { 3, 4 } };
        T566 solution = new T566();

        int[][] result = solution.matrixReshape(nums, 4, 1);

        for (int[] row : result) {
            for (int num : row) {
                System.out.print(num);
                System.out.print(" ");
            }
            System.out.print('\n');
        }
    }

    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int length_row = nums.length;
        if (length_row < 1) {
            return nums;
        }
        int length_col = nums[0].length;
        if (length_col * length_row != r * c) {
            return nums;
        }

        int[][] result = new int[r][c];
        int col = 0;
        int row = 0;
        int count = 0;
        for (int[] rowData : nums) {
            for (int num : rowData) {
                result[row][col] = num;
                count = count + 1;
                col = col + 1;
                if (count == c) {
                    row = row + 1;
                    count = 0;
                    col = 0;
                }
            }
        }

        return result;
    }
}
