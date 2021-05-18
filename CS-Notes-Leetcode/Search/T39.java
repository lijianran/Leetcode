
// 2021.05.18
// Leetcode 第39题
// https://leetcode-cn.com/problems/combination-sum/description/
package Search;

import java.util.ArrayList;
import java.util.List;

public class T39 {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if (candidates == null) {
            return result;
        }

        List<Integer> list = new ArrayList<>();
        backtracking(result, list, candidates, target, 0);

        return result;
    }

    private void backtracking(List<List<Integer>> result, List<Integer> list, final int[] candidates, int target, int start) {
        if (target == 0) {
            result.add(new ArrayList<>(list));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            if (target < candidates[i]) {
                continue;
            }
            list.add(candidates[i]);
            backtracking(result, list, candidates, target - candidates[i], i);
            list.remove(list.size() - 1);
        }
    }
}
