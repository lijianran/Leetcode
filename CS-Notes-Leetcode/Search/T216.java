
// 2021.05.18
// Leetcode 第40题
// https://leetcode-cn.com/problems/combination-sum-iii/description/
package Search;

import java.util.ArrayList;
import java.util.List;

public class T216 {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();

        List<Integer> list = new ArrayList<>();
        backtrackint(result, list, k, n, 1);

        return result;
    }

    private void backtrackint(List<List<Integer>> result, List<Integer> list, int k, int n, int start) {
        if (list.size() == k && n == 0) {
            result.add(new ArrayList<>(list));
            return;
        }

        for (int i = start; i <= 9 && i <= n; i++) {
            list.add(i);
            backtrackint(result, list, k, n - i, i + 1);
            list.remove(list.size() - 1);
        }
    }

}
