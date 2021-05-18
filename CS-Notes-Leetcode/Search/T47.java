
// 2021.05.18
// Leetcode 第46题
// https://leetcode-cn.com/problems/permutations-ii/description/
package Search;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class T47 {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null) {
            return result;
        }

        Arrays.sort(nums); // 排序
        List<Integer> list = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];

        backtracking(result, list, visited, nums);

        return result;
    }

    private void backtracking(List<List<Integer>> result, List<Integer> list, boolean[] visited, int[] nums) {
        if (list.size() == nums.length) {
            // result.add(list);
            result.add(new ArrayList<>(list)); // 重新构造一个list
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (i != 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) {
                continue; // 防止重复
            }

            if (visited[i] == false) {
                visited[i] = true;
                list.add(nums[i]);
                backtracking(result, list, visited, nums);

                list.remove(list.size() - 1); // 删除掉
                visited[i] = false;
            }
        }

    }
}
