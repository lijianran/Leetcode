
// 2021.05.10
// Leetcode 第763题
// https://leetcode-cn.com/problems/partition-labels/
package Greed;

import java.util.ArrayList;
import java.util.List;

public class T763 {
    public static void main(String[] args) {
        T763 solution = new T763();
        List<Integer> result = solution.partitionLabels("ababcbacadefegdehijhklij");
        for (Integer integer : result) {
            System.out.println(integer);
        }
    }

    public List<Integer> partitionLabels(String S) {
        int[] lastIndexOfChar = new int[26];
        for (int i = 0; i < S.length(); i++) {
            lastIndexOfChar[char2Index(S.charAt(i))] = i;
        }

        List<Integer> partitions = new ArrayList<>();
        int firstIndex = 0;
        while (firstIndex < S.length()) {
            int lastIndex = firstIndex;
            for (int i = firstIndex; i < S.length() && i <= lastIndex; i++) {
                int index = lastIndexOfChar[char2Index(S.charAt(i))];
                if (index > lastIndex) {
                    lastIndex = index;
                }
            }

            partitions.add(lastIndex - firstIndex + 1);
            firstIndex = lastIndex + 1;
        }

        return partitions;
    }

    private int char2Index(char c) {
        return c - 'a';
    }
}
