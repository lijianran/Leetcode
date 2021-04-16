
// 2021.04.16
// Leetcode 第240题
// https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
package ArrayAndMatrix;

public class T240 {
    public static void main(String[] args) {
        int[][] matrix = { { 1, 4, 7, 11, 15 }, { 2, 5, 8, 12, 19 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 },
                { 18, 21, 23, 26, 30 } };

        T240 solution = new T240();
        System.out.println(solution.searchMatrix(matrix, 20));
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null)
            return false;
        int row = matrix.length;
        if (row < 1) {
            return false;
        }
        int col = matrix[0].length;

        for (int i = col - 1; i >= 0; i--) {
            if (target >= matrix[0][i]) {
                for (int j = 0; j < row; j++) {
                    if (target == matrix[j][i]) {
                        return true;
                    }

                    if (target < matrix[j][i]) {
                        break;
                    }
                }
            }
        }

        return false;
    }
}
