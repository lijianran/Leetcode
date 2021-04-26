
// 2021.04.26
// Leetcode 第230题
// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/description/
package Tree;

public class T230 {
    private int count = 0;
    private int result = 0;

    public int kthSmallest(TreeNode root, int k) {
        inOrder(root, k);
        return result;
    }

    private void inOrder(TreeNode root, int k) {
        if (root == null) {
            return;
        }

        inOrder(root.left, k);
        count++;
        if (count == k) {
            result = root.val;
            return;
        }
        inOrder(root.right, k);
    }
}
