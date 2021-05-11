
// 2021.05.11
// Leetcode 第69题
// https://leetcode-cn.com/problems/sqrtx/description/
package BinarySearch;

public class T69 {
    public static void main(String[] args) {
        T69 solution = new T69();
        System.out.println(solution.mySqrt(8));
    }

    public int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int l = 0;
        int h = x;
        while (l <= h) {
            int m = l + (h - l) / 2;
            int sqrt = x / m;
            if (sqrt == m) {
                return m;
            } else if (sqrt < m) {
                h = m - 1;
            } else {
                l = m + 1;
            }
            // 乘法溢出
            // if (m * m == x) {
            // return m;
            // } else if (m * m > x) {
            // h = m - 1;
            // } else {
            // l = m + 1;
            // }
        }

        return h;
    }
}
