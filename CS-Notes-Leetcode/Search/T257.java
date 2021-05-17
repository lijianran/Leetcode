
// 2021.05.17
// Leetcode 第257题
// https://leetcode-cn.com/problems/binary-tree-paths/description/
package Search;

import java.util.ArrayList;
import java.util.List;
import Tree.TreeNode;

public class T257 {
    public static void main(String[] args) {
        T257 solution = new T257();
        TreeNode a = new TreeNode(1);
        TreeNode b = new TreeNode(2);
        TreeNode c = new TreeNode(3);
        TreeNode d = new TreeNode(5);
        a.left = b;
        a.right = c;
        b.right = d;

        List<String> results = solution.binaryTreePaths(a);
        for (String string : results) {
            System.out.println(string);
        }
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<>();
        if (root == null) {
            return paths;
        }
        List<String> temp = new ArrayList<>();

        backtracking(temp, paths, root);
        return paths;
    }

    private void backtracking(List<String> temp, List<String> paths, TreeNode node) {

        temp.add(Integer.toString(node.val));

        if (node.left == null && node.right == null) {
            paths.add(buildPath(temp));
        }

        if (node.left != null) {
            backtracking(temp, paths, node.left);
        }

        if (node.right != null) {
            backtracking(temp, paths, node.right);
        }

        temp.remove(temp.size() - 1);

    }

    private String buildPath(List<String> temp) {
        StringBuilder tempPath = new StringBuilder();
        for (int i = 0; i < temp.size(); i++) {
            if (tempPath.length() != 0) {
                tempPath.append("->");
            }
            tempPath.append(temp.get(i));
        }

        return tempPath.toString();
    }
}
