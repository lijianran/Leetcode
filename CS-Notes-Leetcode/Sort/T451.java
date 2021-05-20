
// 2021.05.20
// Leetcode 第451题
// https://leetcode-cn.com/problems/sort-characters-by-frequency/description/
// 桶排序
package Sort;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class T451 {
    public static void main(String[] args) {
        T451 solution = new T451();
        System.out.println(solution.frequencySort("tree"));
        System.out.println(solution.frequencySort("cccaaa"));
        System.out.println(solution.frequencySort("Aabb"));

    }

    @SuppressWarnings("unchecked")
    public String frequencySort(String s) {
        Map<Character, Integer> frequency = new HashMap<>();
        for (Character c : s.toCharArray()) {
            frequency.put(c, frequency.getOrDefault(c, 0) + 1);
        }

        List<Character>[] buckets = new ArrayList[s.length() + 1];
        for (char c : frequency.keySet()) {
            int f = frequency.get(c);
            if (buckets[f] == null) {
                buckets[f] = new ArrayList<>();
            }
            buckets[f].add(c);
        }

        StringBuilder string = new StringBuilder();
        for (int i = buckets.length - 1; i >= 0; i--) {
            if (buckets[i] == null) {
                continue;
            }

            for (char c : buckets[i]) {
                for (int j = 0; j < i; j++) {
                    string.append(c);
                }
            }
        }

        return string.toString();
    }
}
