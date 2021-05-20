
// 2021.05.20
// Leetcode 第347题
// https://leetcode-cn.com/problems/top-k-frequent-elements/
// 桶排序
package Sort;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class T347 {
    public static void main(String[] args) {
        int[] nums = { 1, 1, 1, 2, 2, 3 };
        int[] nums2 = { 1 };

        T347 solution = new T347();
        int[] result = solution.topKFrequent(nums, 2);
        int[] result2 = solution.topKFrequent(nums2, 1);

        for (int i : result) {
            System.out.println(i);
        }

        for (int i : result2) {
            System.out.println(i);
        }
    }

    @SuppressWarnings("unchecked")
    public int[] topKFrequent(int[] nums, int k) {
        int[] result = new int[k];

        Map<Integer, Integer> frequency = new HashMap<>();
        for (int num : nums) {
            frequency.put(num, frequency.getOrDefault(num, 0) + 1);
        }

        List<Integer>[] buckets = new ArrayList[nums.length + 1]; // 频率，长度加一，没有0次
        for (int key : frequency.keySet()) {
            int f = frequency.get(key);
            if (buckets[f] == null) {
                buckets[f] = new ArrayList<>();
            }
            buckets[f].add(key);
        }

        List<Integer> topK = new ArrayList<>();
        for (int i = buckets.length - 1; i >= 0 && topK.size() < k; i--) {
            if (buckets[i] == null) {
                continue;
            }

            if (buckets[i].size() <= (k - topK.size())) {
                topK.addAll(buckets[i]);
            } else {
                topK.addAll(buckets[i].subList(0, k - topK.size()));
            }
        }

        for (int i = 0; i < k; i++) {
            result[i] = topK.get(i);
        }
        return result;
    }
}
