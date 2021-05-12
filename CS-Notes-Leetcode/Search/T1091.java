
// 2021.05.12
// Leetcode 第1091题
// https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/
package Search;

import java.util.LinkedList;
import java.util.Queue;

public class T1091 {
    public static void main(String[] args) {
        int[][] grid = { { 0, 1 }, { 1, 0 } };
        int[][] grid2 = { { 0, 0, 0 }, { 1, 1, 0 }, { 1, 1, 0 } };
        int[][] grid3 = { { 1, 0, 0 }, { 1, 1, 0 }, { 1, 1, 0 } };
        T1091 solution = new T1091();
        System.out.println(solution.shortestPathBinaryMatrix(grid));
        System.out.println(solution.shortestPathBinaryMatrix(grid2));
        System.out.println(solution.shortestPathBinaryMatrix(grid3));

    }

    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return -1;
        }
        int[][] direction = { { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, 1 }, { 0, -1 }, { -1, -1 }, { -1, 1 }, { -1, 0 } };
        int m = grid.length;
        int n = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[] { 0, 0 });
        int pathLength = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            pathLength++;
            while (size-- > 0) {
                int[] cur = queue.poll();
                int curx = cur[0];
                int cury = cur[1];
                if (grid[curx][cury] == 1) {
                    continue;
                }
                if (curx == m - 1 && cury == n - 1) {
                    return pathLength;
                }

                grid[curx][cury] = 1;
                for (int[] d : direction) {
                    int newx = curx + d[0];
                    int newy = cury + d[1];
                    if (newx < 0 || newx >= m || newy < 0 || newy >= n) {
                        continue;
                    }
                    queue.add(new int[] { newx, newy });
                }

            }
        }
        return -1;
    }
}
