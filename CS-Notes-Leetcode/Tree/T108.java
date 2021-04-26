
// 2021.04.26
// Leetcode 第108题
// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
package Tree;

public class T108 {
    public TreeNode sortedArrayToBST(int[] nums) {
        return toBST(nums, 0, nums.length - 1);
    }

    private TreeNode toBST(int[] nums, int low, int high) {
        if (low > high) {
            return null;
        }

        int middle = (low + high) / 2;
        TreeNode root = new TreeNode(nums[middle]);
        root.left = toBST(nums, low, middle - 1);
        root.right = toBST(nums, middle + 1, high);

        return root;
    }
}
