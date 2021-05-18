
// 2021.05.18
// Leetcode 第46题
// https://leetcode-cn.com/problems/combinations/description/
package Search;

import java.util.ArrayList;
import java.util.List;

public class T77 {
    public static void main(String[] args) {
        T77 solution = new T77();

        List<List<Integer>> result = solution.combine(4, 2);
        for (List<Integer> list : result) {
            for (Integer num : list) {
                System.out.print(num);
            }
            System.out.println();
        }
    }

    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        if (n == 0 || k == 0 || n < k) {
            return result;
        }

        List<Integer> list = new ArrayList<>();
        // boolean[] visited = new boolean[n];

        // backtracking(result, list, visited, n, k, 1);
        backtracking(result, list, n, k, 1);

        return result;
    }

    private void backtracking(List<List<Integer>> result, List<Integer> list, final int n, int k, int cur) {
        // if (list.size() == k) {
        // result.add(new ArrayList<>(list));
        // }
        if (k == 0) {
            result.add(new ArrayList<>(list));
            return;
        }

        for (int i = cur; i <= n - k + 1; i++) {
            // if (visited[i] == false) {
            // visited[i] = true;
            list.add(i);

            backtracking(result, list, n, k - 1, i + 1);

            list.remove(list.size() - 1);
            // visited[i] = false;
            // }
        }
    }

}
