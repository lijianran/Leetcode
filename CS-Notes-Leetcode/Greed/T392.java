
// 2021.05.10
// Leetcode 第392题
// https://leetcode-cn.com/problems/is-subsequence/
package Greed;

public class T392 {
    public static void main(String[] args) {
        T392 solution = new T392();
        System.out.println(solution.isSubsequence("abc", "ahbgdc"));
        System.out.println(solution.isSubsequence("axc", "ahbgdc"));
    }

    public boolean isSubsequence(String s, String t) {
        int index = -1;
        for (char c : s.toCharArray()) {
            index = t.indexOf(c, index + 1);
            if (index == -1) {
                return false;
            }
        }
        return true;
    }
}
