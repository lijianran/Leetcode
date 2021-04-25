
// 2021.04.25
// Leetcode 第144题
// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
package Tree;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class T144 {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            if (node == null) {
                continue;
            }

            result.add(node.val);
            // 栈结构，先右后左，则左节点先出栈，确保先遍历左节点
            stack.push(node.right);
            stack.push(node.left);
        }

        return result;
    }
}
