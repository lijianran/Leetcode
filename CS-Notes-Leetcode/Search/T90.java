
// 2021.05.19
// Leetcode 第90题
// https://leetcode-cn.com/problems/subsets-ii/description/
package Search;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class T90 {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null) {
            return result;
        }

        List<Integer> list = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        Arrays.sort(nums);

        for (int size = 0; size <= nums.length; size++) {
            backtracking(result, list, visited, nums, size, 0);
        }

        return result;
    }

    private void backtracking(List<List<Integer>> result, List<Integer> list, boolean[] visited, final int[] nums,
            final int size, int start) {
        if (list.size() == size) {
            result.add(new ArrayList<>(list));
            return;
        }

        for (int i = start; i < nums.length; i++) {
            if (i != 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) {
                continue;
            }

            if (visited[i] == false) {
                visited[i] = true;
                list.add(nums[i]);
                backtracking(result, list, visited, nums, size, i + 1);
                list.remove(list.size() - 1);
                visited[i] = false;
            }
        }
    }
}
