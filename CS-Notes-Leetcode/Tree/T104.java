
// 2021.04.23
// Leetcode 第104题
// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
package Tree;

public class T104 {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }
}
