
// 2021.04.25
// Leetcode 第145题
// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
package Tree;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

public class T145 {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.add(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            if (node == null) {
                continue;
            }
            result.add(node.val);
            stack.push(node.left);
            stack.push(node.right);
        }

        Collections.reverse(result);
        return result;
    }
}
