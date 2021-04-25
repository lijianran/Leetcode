
// 2021.04.25
// Leetcode 第94题
// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
package Tree;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class T94 {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            TreeNode node = stack.pop();
            result.add(node.val);
            cur = node.right;
        }

        return result;
    }
}
