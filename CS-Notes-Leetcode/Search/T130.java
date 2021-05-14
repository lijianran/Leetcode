
// 2021.05.14
// Leetcode 第130题
// https://leetcode-cn.com/problems/surrounded-regions/description/
package Search;

public class T130 {
    private int m, n;
    private int[][] direction = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };

    public void solve(char[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) {
            return;
        }

        m = board.length;
        n = board[0].length;

        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }

        for (int i = 0; i < n; i++) {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

    }

    private void dfs(char[][] board, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O') {
            return;
        }

        board[row][col] = 'T';
        
        for (int[] d : direction) {
            dfs(board, row + d[0], col + d[1]);
        }
    }
}
