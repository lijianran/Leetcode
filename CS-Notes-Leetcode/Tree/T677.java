
// 2021.04.30
// Leetcode 第677题
// https://leetcode-cn.com/problems/map-sum-pairs/description/
package Tree;

public class T677 {

    private class Node {
        Node[] childs = new Node[26];
        int value;
    }

    private Node root = new Node();

    /** Initialize your data structure here. */
    public T677() {

    }

    public void insert(String key, int val) {
        insert(key, val, root);
    }

    private void insert(String key, int val, Node node) {
        if (node == null) {
            return;
        }
        if (key.length() == 0) {
            node.value = val;
            return;
        }
        int index = indexOfChar(key.charAt(0));
        if (node.childs[index] == null) {
            node.childs[index] = new Node();
        }
        insert(key.substring(1), val, node.childs[index]);
    }

    public int sum(String prefix) {
        return sum(prefix, root);
    }

    private int sum(String prefix, Node node) {
        if (node == null) {
            return 0;
        }
        if (prefix.length() != 0) {
            int index = indexOfChar(prefix.charAt(0));
            return sum(prefix.substring(1), node.childs[index]);
        }
        int sum = node.value;
        for (Node child : node.childs) {
            sum += sum(prefix, child);
        }
        return sum;
    }

    private int indexOfChar(char c) {
        return c - 'a';
    }
}
