
// 2021.04.30
// Leetcode 第501题
// https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
package Tree;

import java.util.ArrayList;
import java.util.List;

public class T501 {
    private int curCount = 1;
    private int maxCount = 1;
    private TreeNode preNode = null;

    public int[] findMode(TreeNode root) {
        if (root == null) {
            return new int[] {};
        }

        List<Integer> nums = new ArrayList<>();
        InOrder(root, nums);

        int[] result = new int[nums.size()];
        int index = 0;
        for (Integer num : nums) {
            result[index++] = num;
        }

        return result;
    }

    private void InOrder(TreeNode root, List<Integer> nums) {
        if (root == null) {
            return;
        }
        InOrder(root.left, nums);
        if (preNode != null) {
            if (preNode.val == root.val) {
                curCount++;
            } else {
                curCount = 1;
            }
        }

        if (curCount > maxCount) {
            maxCount = curCount;
            nums.clear();
            nums.add(root.val);
        } else if (curCount == maxCount) {
            nums.add(root.val);
        }

        preNode = root;

        InOrder(root.right, nums);
    }
}
