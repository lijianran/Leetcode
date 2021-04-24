
// 2021.04.24
// Leetcode 第671题
// https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/
package Tree;

public class T671 {
    public int findSecondMinimumValue(TreeNode root) {
        if (root == null) {
            return -1;
        }

        if (root.left == null && root.right == null) {
            return -1;
        }

        int leftVal = root.left.val;
        int rightVal = root.right.val;

        if (leftVal == root.val) {
            leftVal = findSecondMinimumValue(root.left);
        }
        if (rightVal == root.val) {
            rightVal = findSecondMinimumValue(root.right);
        }

        if (leftVal != -1 && rightVal != -1) {
            return Math.min(leftVal, rightVal);
        }

        if (leftVal != -1) {
            return leftVal;
        }

        return rightVal;
    }
}
