
// 2021.04.30
// Leetcode 第653题
// https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/description/
package Tree;

import java.util.ArrayList;
import java.util.List;

public class T653 {
    public boolean findTarget(TreeNode root, int k) {
        List<Integer> nums = new ArrayList<>();
        InOrder(root, nums);

        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int sum = nums.get(i) + nums.get(j);
            if (sum == k) {
                return true;
            }

            if (sum < k) {
                i++;
            } else {
                j--;
            }
        }

        return false;
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
