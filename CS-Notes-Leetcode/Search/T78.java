
// 2021.05.19
// Leetcode 第78题
// https://leetcode-cn.com/problems/subsets/description/
package Search;

import java.util.ArrayList;
import java.util.List;

public class T78 {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null) {
            return result;
        }
        List<Integer> list = new ArrayList<>();

        for (int size = 0; size <= nums.length; size++) {
            backtracking(result, list, nums, size, 0);

        }

        return result;
    }

    private void backtracking(List<List<Integer>> result, List<Integer> list, int[] nums, final int size,
            final int start) {
        if (list.size() == size) {
            result.add(new ArrayList<>(list));
            return;
        }

        for (int i = start; i < nums.length; i++) {
            list.add(nums[i]);

            backtracking(result, list, nums, size, i + 1);

            list.remove(list.size() - 1);
        }

    }
}
