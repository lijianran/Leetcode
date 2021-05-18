
// 2021.05.18
// Leetcode 第40题
// https://leetcode-cn.com/problems/combination-sum-ii/description/
package Search;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class T40 {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if (candidates == null) {
            return result;
        }

        List<Integer> list = new ArrayList<>();
        boolean[] visited = new boolean[candidates.length];
        Arrays.sort(candidates);

        backtracking(result, list, visited, candidates, target, 0);

        return result;
    }

    private void backtracking(List<List<Integer>> result, List<Integer> list, boolean[] visited, int[] candidates,
            int target, int start) {
        if (target == 0) {
            result.add(new ArrayList<>(list));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            if (i != 0 && candidates[i] == candidates[i - 1] && visited[i - 1] == false) {
                continue;
            }

            if (visited[i] == false && candidates[i] <= target) {
                visited[i] = true;
                list.add(candidates[i]);
                backtracking(result, list, visited, candidates, target - candidates[i], i + 1);
                list.remove(list.size() - 1);
                visited[i] = false;
            }
        }
    }
}
