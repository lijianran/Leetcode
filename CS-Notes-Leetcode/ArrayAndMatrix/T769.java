
// 2021.04.19
// Leetcode 第769题
// https://leetcode-cn.com/problems/max-chunks-to-make-sorted/
package ArrayAndMatrix;

public class T769 {
    public static void main(String[] args) {
        int[] arr = {1,0,2,3,4};
        T769 solution = new T769();
        System.out.println(solution.maxChunksToSorted(arr));
    }

    public int maxChunksToSorted(int[] arr) {
        if (arr == null) {
            return 0;
        }
        int result = 0;
        int right = arr[0];
        for (int i = 0; i < arr.length; i++) {
            right = Math.max(right, arr[i]);
            if (right == i) {
                result++;
            }
        }
        return result;
    }
}
