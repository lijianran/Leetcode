
// 2021.05.19
// Leetcode 第131题
// https://leetcode-cn.com/problems/palindrome-partitioning/description/
package Search;

import java.util.ArrayList;
import java.util.List;

public class T131 {
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        List<String> list = new ArrayList<>();

        backtracking(result, list, s);

        return result;
    }

    private void backtracking(List<List<String>> result, List<String> list, String s) {
        if (s.length() == 0) {
            result.add(new ArrayList<>(list));
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            if (isPalindrome(s, 0, i)) {
                list.add(s.substring(0, i + 1));
                backtracking(result, list, s.substring(i + 1));
                list.remove(list.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String s, int start, int end) {
        while (start < end) {
            if (s.charAt(start++) != s.charAt(end--)) {
                return false;
            }
        }
        return true;
    }
}
