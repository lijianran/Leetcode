
// 2021.05.12
// Leetcode 第95题
// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
package Divide;

import java.util.LinkedList;
import java.util.List;
import Tree.TreeNode;

public class T95 {
    public static void main(String[] args) {

    }

    public List<TreeNode> generateTrees(int n) {
        if (n < 1) {
            return new LinkedList<TreeNode>();
        }
        return generateSubTrees(1, n);
    }

    private List<TreeNode> generateSubTrees(int start, int end) {
        List<TreeNode> res = new LinkedList<TreeNode>();
        if (start > end) {
            res.add(null);
            return res;
        }

        for (int i = start; i <= end; i++) {
            List<TreeNode> leftSubTrees = generateSubTrees(start, i - 1);
            List<TreeNode> rightSubTrees = generateSubTrees(i + 1, end);
            for (TreeNode left : leftSubTrees) {
                for (TreeNode right : rightSubTrees) {
                    TreeNode root = new TreeNode(i);
                    root.left = left;
                    root.right = right;
                    res.add(root);
                }
            }
        }

        return res;
    }
}
