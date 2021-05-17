
// 2021.05.17
// Leetcode 第17题
// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
package Search;

import java.util.ArrayList;
import java.util.List;

public class T17 {
    private static final String[] KEYS = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    public static void main(String[] args) {
        T17 solution = new T17();
        List<String> result = solution.letterCombinations("23");
        for (String string : result) {
            System.out.println(string);
        }
    }

    public List<String> letterCombinations(String digits) {
        List<String> combinations = new ArrayList<>();
        if (digits == null || digits.length() == 0) {
            return combinations;
        }

        doCombination(new StringBuilder(), combinations, digits);
        return combinations;
    }

    private void doCombination(StringBuilder prefix, List<String> combinations, final String digits) {
        if (prefix.length() == digits.length()) {
            combinations.add(prefix.toString());
            return;
        }

        int curDigit = digits.charAt(prefix.length()) - '0';
        String letters = KEYS[curDigit];
        for (char c : letters.toCharArray()) {
            prefix.append(c);
            doCombination(prefix, combinations, digits);
            prefix.deleteCharAt(prefix.length() - 1);
        }
    }
}
