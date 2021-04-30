
// 2021.04.30
// Leetcode 第530题
// https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/description/
package Tree;

import java.util.ArrayList;
import java.util.List;

public class T530 {
    public int getMinimumDifference(TreeNode root) {
        if (root == null) {
            return -1;
        }
        List<Integer> nums = new ArrayList<>();
        InOrder(root, nums);

        int i = 0;
        int j = 1;
        int result = Integer.MAX_VALUE;
        for (; j < nums.size(); ++i, ++j) {
            int pre = nums.get(i);
            int cur = nums.get(j);
            int temp = cur - pre;
            result = Math.min(result, temp);
        }
        return result;
    }

    private void InOrder(TreeNode root, List<Integer> nums) {
        if (root == null) {
            return;
        }
        InOrder(root.left, nums);
        nums.add(root.val);
        InOrder(root.right, nums);
    }
}
