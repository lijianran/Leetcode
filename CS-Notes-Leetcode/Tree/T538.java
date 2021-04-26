
// 2021.04.26
// Leetcode 第538题
// https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
package Tree;

public class T538 {
    private int sum = 0;

    public TreeNode convertBST(TreeNode root) {
        order(root);
        return root;
    }

    private void order(TreeNode root) {
        if (root == null) {
            return;
        }

        order(root.right);
        sum += root.val;
        root.val = sum;
        order(root.left);
    }
}
