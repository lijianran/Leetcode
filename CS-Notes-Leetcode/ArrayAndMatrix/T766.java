
// 2021.04.19
// Leetcode 第766题
// https://leetcode-cn.com/problems/toeplitz-matrix/description/
package ArrayAndMatrix;

public class T766 {
    public static void main(String[] args) {
        // int[][] matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
        int[][] matrix2 = {{1,2}, {2,2}};

        T766 solution = new T766();
        System.out.println(solution.isToeplitzMatrix(matrix2));
    }

    public boolean isToeplitzMatrix(int[][] matrix) {
        for (int i = 0; i < matrix[0].length; i++) {
            if (!check(matrix, matrix[0][i], 0, i)) {
                return false;
            }
        }

        for (int i = 0; i < matrix.length; i++) {
            if (!check(matrix, matrix[i][0], i, 0)) {
                return false;
            }
        }

        return true;
    }

    private boolean check(int[][] matrix, int expectValue, int row, int col) {
        if (row >= matrix.length || col >= matrix[0].length) {
            return true;
        }
        if (matrix[row][col] != expectValue) {
            return false;
        }
        return check(matrix, expectValue, row + 1, col + 1);
    }
}
