
// 2021.04.21
// Leetcode 第524题
// https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/description/
package DoublePointer;

import java.util.Arrays;
import java.util.List;

public class T524 {
    public static void main(String[] args) {
        List<String> dictionary = Arrays.asList("ale","apple","monkey","plea");
        T524 solution = new T524();
        System.out.println(solution.findLongestWord("abpcplea", dictionary));
    }

    public String findLongestWord(String s, List<String> dictionary) {
        String longestWord = "";
        for (String string : dictionary) {
            int maxLength = longestWord.length();
            int curLength = string.length();
            if (maxLength > curLength || (maxLength == curLength && longestWord.compareTo(string) < 0)) {
                continue;
            }
            if (isSubStr(s, string)) {
                longestWord = string;
            }
        }
        return longestWord;
    }

    private Boolean isSubStr(String a, String b) {
        int j = 0;
        for (int i = 0; i < a.length() && j < b.length(); i++) {
            if (a.charAt(i) == b.charAt(j)) {
                j++;
            }
        }
        return j == b.length();
    }
}
