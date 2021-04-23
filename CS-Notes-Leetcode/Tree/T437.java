
// 2021.04.23
// Leetcode 第437题
// https://leetcode-cn.com/problems/path-sum-iii/description/
package Tree;

public class T437 {
    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return 0;
        }
        // 分解问题
        return pathSumWithRoot(root, targetSum) + pathSum(root.left, targetSum) + pathSum(root.right, targetSum);
    }

    private int pathSumWithRoot(TreeNode root, int targetSum) {
        if (root == null) {
            return 0;
        }

        // 先序遍历
        int count = 0;
        if (root.val == targetSum) {
            count++;
        }
        count += pathSumWithRoot(root.left, targetSum - root.val) + pathSumWithRoot(root.right, targetSum - root.val);

        return count;
    }
}
