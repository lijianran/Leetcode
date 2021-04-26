
// 2021.04.26
// Leetcode 第235题
// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
package Tree;

public class T235 {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root.val > p.val && root.val > q.val) {
            return lowestCommonAncestor(root.left, p, q);
        }
        if (root.val < p.val && root.val < q.val) {
            return lowestCommonAncestor(root.right, p, q);
        }
        return root;
    }
}
