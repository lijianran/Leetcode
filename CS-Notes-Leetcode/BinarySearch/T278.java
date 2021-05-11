
// 2021.05.11
// Leetcode 第278题
// https://leetcode-cn.com/problems/first-bad-version/description/
package BinarySearch;

public class T278 {
    public int firstBadVersion(int n) {
        int l = 0;
        int h = n;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (isBadVersion(m)) {
                h = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }

    private boolean isBadVersion(int version) {
        return true;
    }
}
