
// 2021.05.14
// Leetcode 第417题
// https://leetcode-cn.com/problems/pacific-atlantic-water-flow/description/
package Search;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class T417 {
    private int m, n;
    private int[][] direction = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };
    private int[][] heights;

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> result = new ArrayList<>();
        if (heights == null || heights.length == 0 || heights[0].length == 0) {
            return result;
        }

        m = heights.length;
        n = heights[0].length;
        this.heights = heights;

        boolean[][] canReachP = new boolean[m][n];
        boolean[][] canReachA = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            dfs(i, 0, canReachP);
            dfs(i, n - 1, canReachA);
        }

        for (int i = 0; i < n; i++) {
            dfs(0, i, canReachP);
            dfs(m - 1, i, canReachA);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (canReachA[i][j] && canReachP[i][j]) {
                    result.add(Arrays.asList(i, j));
                }
            }
        }

        return result;
    }

    private void dfs(int row, int col, boolean[][] canReach) {
        if (canReach[row][col]) {
            return;
        }

        canReach[row][col] = true;

        for (int[] d : direction) {
            int nextRow = row + d[0];
            int nextCol = col + d[1];

            if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n
                    || heights[row][col] > heights[nextRow][nextCol]) {
                continue;
            }

            dfs(nextRow, nextCol, canReach);
        }
    }
}
