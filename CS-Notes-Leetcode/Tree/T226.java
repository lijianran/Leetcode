
// 2021.04.23
// Leetcode 第226题
// https://leetcode-cn.com/problems/invert-binary-tree/description/
package Tree;

public class T226 {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode left = root.left;
        root.left = invertTree(root.right);
        root.right = invertTree(left);
        return root;
    }
}
