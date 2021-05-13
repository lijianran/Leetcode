
// 2021.05.13
// Leetcode 第200题
// https://leetcode-cn.com/problems/number-of-islands/description/
package Search;

public class T200 {
    private int m, n;
    private int[][] direction = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        m = grid.length;
        n = grid[0].length;

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '0') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }

    private void dfs(char[][] grid, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';
        for (int[] d : direction) {
            dfs(grid, row + d[0], col + d[1]);
        }
    }
}
