
// 2021.04.25
// Leetcode 第513题
// https://leetcode-cn.com/problems/find-bottom-left-tree-value/description/
package Tree;

import java.util.LinkedList;
import java.util.Queue;

public class T513 {
    public int findBottomLeftValue(TreeNode root) {
        if (root == null) {
            return -1;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            root = queue.poll();
            // 先右边
            if (root.right != null) {
                queue.add(root.right);
            }
            // 后左
            if (root.left != null) {
                queue.add(root.left);
            }
        }

        return root.val;
    }
}
