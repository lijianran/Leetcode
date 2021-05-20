
// 2021.05.20
// Leetcode 第215题
// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
// 快速排序
package Sort;

public class T215 {
    public static void main(String[] args) {
        int[] nums = { 3, 2, 1, 5, 6, 4 };
        int[] nums2 = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
        
        T215 solution = new T215();

        System.out.println(solution.findKthLargest(nums, 2));
        System.out.println(solution.findKthLargest(nums2, 4));

    }

    public int findKthLargest(int[] nums, int k) {
        k = nums.length - k;
        int low = 0;
        int high = nums.length - 1;
        while (low < high) {
            int p = partition(nums, low, high);
            if (p == k) {
                break;
            } else if (p < k) {
                low = p + 1;
            } else {
                high = p - 1;
            }
        }

        return nums[k];
    }

    private int partition(int[] nums, int low, int high) {
        int i = low;
        int j = high + 1;
        while (true) {
            while (nums[++i] < nums[low] && i < high)
                ;
            while (nums[--j] > nums[low] && j > low)
                ;

            if (i >= j) {
                break;
            }

            swap(nums, i, j);
        }

        swap(nums, low, j);

        return j;
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
