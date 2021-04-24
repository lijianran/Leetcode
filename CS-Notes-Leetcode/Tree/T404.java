
// 2021.04.24
// Leetcode 第111题
// https://leetcode-cn.com/problems/sum-of-left-leaves/description/
package Tree;

public class T404 {
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }

        if (root.left != null && root.left.left == null && root.left.right == null) {
            return root.left.val + sumOfLeftLeaves(root.right);
        }
        
        return sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
    }
}
