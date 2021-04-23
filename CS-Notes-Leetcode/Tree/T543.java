
// 2021.04.23
// Leetcode 第543题
// https://leetcode-cn.com/problems/diameter-of-binary-tree/description/
package Tree;

public class T543 {
    private int diameter = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        depth(root);
        return diameter;
    }

    private int depth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left = depth(root.left);
        int right = depth(root.right);
        diameter = Math.max(diameter, left + right);
        return 1 + Math.max(left, right);
    }
}
