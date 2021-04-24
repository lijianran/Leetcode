
// 2021.04.24
// Leetcode 第786题
// https://leetcode-cn.com/problems/longest-univalue-path/
package Tree;

public class T687 {
    private int m_max = 0;

    public int longestUnivaluePath(TreeNode root) {
        dfs(root);
        return m_max;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left = dfs(root.left);

        int right = dfs(root.right);

        int leftpath = (root.left != null && root.val == root.left.val) ? left + 1 : 0;
        int rightpath = (root.right != null && root.val == root.right.val) ? right + 1 : 0;
        m_max = Math.max(m_max, leftpath + rightpath);

        return Math.max(leftpath, rightpath);
    }
}
