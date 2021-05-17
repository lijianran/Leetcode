
// 2021.05.17
// Leetcode 第79题
// https://leetcode-cn.com/problems/word-search/description/
package Search;

public class T79 {
    private static final int[][] direction = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    private int m;
    private int n;

    public boolean exist(char[][] board, String word) {
        if (word == null || word.length() == 0) {
            return true;
        }
        if (board == null || board.length == 0 || board[0].length == 0) {
            return false;
        }

        m = board.length;
        n = board[0].length;
        boolean[][] hasVisited = new boolean[m][n];

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (backtracking(0, row, col, hasVisited, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }

    private boolean backtracking(int curLen, int row, int col, boolean[][] visited, final char[][] board,
            final String word) {
        if (curLen == word.length()) {
            return true;
        }

        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word.charAt(curLen) || visited[row][col]) {
            return false;
        }

        visited[row][col] = true;

        for (int[] d : direction) {
            if (backtracking(curLen + 1, row + d[0], col + d[1], visited, board, word)){
                return true;
            }
        }

        visited[row][col] = false;

        return false;
    }
}