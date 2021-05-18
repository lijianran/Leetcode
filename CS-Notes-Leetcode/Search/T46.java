
// 2021.05.18
// Leetcode 第46题
// https://leetcode-cn.com/problems/permutations/description/
package Search;

import java.util.ArrayList;
import java.util.List;

public class T46 {
    public static void main(String[] args) {
        T46 solution = new T46();
        int[] nums = { 1, 2, 3 };
        List<List<Integer>> result = solution.permute(nums);
        for (List<Integer> list : result) {
            for (Integer num : list) {
                System.out.print(num);
            }
            System.out.println();
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null) {
            return result;
        }

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
