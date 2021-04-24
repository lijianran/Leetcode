
// 2021.04.24
// Leetcode 第337题
// https://leetcode-cn.com/problems/house-robber-iii/
package Tree;

import java.util.HashMap;
import java.util.Map;

public class T337 {
    private Map<TreeNode, Integer> cache = new HashMap<>();

    public int rob(TreeNode root) {
        if (root == null) {
            return 0;
        }

        if (cache.containsKey(root)) {
            return cache.get(root);
        }

        int val1 = root.val;
        if (root.left != null) {
            val1 += rob(root.left.left) + rob(root.left.right);
        }
        if (root.right != null) {
            val1 += rob(root.right.left) + rob(root.right.right);
        }

        int val2 = rob(root.left) + rob(root.right);

        int result = Math.max(val1, val2);
        cache.put(root, result);

        return result;
    }
}
