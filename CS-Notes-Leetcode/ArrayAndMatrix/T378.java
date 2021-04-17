
// 2021.04.17
// Leetcode 第378题
// https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
package ArrayAndMatrix;

public class T378 {
    public static void main(String[] args) {
        int[][] matrix = { { 1, 5, 9 }, { 10, 11, 13 }, { 12, 13, 15 } };
        // int[][] matrix1 = { { -5 } };
        T378 solution = new T378();
        System.out.println(solution.kthSmallest(matrix, 1));
    }

    public int kthSmallest(int[][] matrix, int k) {
        int m = matrix.length;
        int n = matrix[0].length;
        int low = matrix[0][0];
        int high = matrix[m - 1][n - 1];

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n && matrix[i][j] <= mid; j++) {
                    count++;
                }
            }
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
}
