
// 2021.05.07
// Leetcode 第455题
// https://leetcode-cn.com/problems/assign-cookies/description/
package Greed;

import java.util.Arrays;

public class T455 {
    public static void main(String[] args) {
        T455 solution = new T455();
        int[] g = { 1, 2 };
        int[] s = { 1, 2, 3 };
        System.out.println(solution.findContentChildren(g, s));
    }

    public int findContentChildren(int[] g, int[] s) {
        if (g == null || s == null) {
            return 0;
        }
        Arrays.sort(g);
        Arrays.sort(s);
        int gi = 0;
        int si = 0;
        while (gi < g.length && si < s.length) {
            if (g[gi] <= s[si]) {
                gi++;
            }
            si++;
        }

        return gi;
    }
}
