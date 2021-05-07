
// 2021.05.07
// Leetcode 第435题
// https://leetcode-cn.com/problems/non-overlapping-intervals/description/
package Greed;

import java.util.Arrays;
import java.util.Comparator;

public class T435 {
    public static void main(String[] args) {
        T435 solution = new T435();
        // int[][] intervals = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 3 } };
        int[][] intervals2 = { { 1, 2 }, { 2, 3 } };

        System.out.println(solution.eraseOverlapIntervals(intervals2));
    }

    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        // 按数组第二个数字排序，从小到大
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return (o1[1] < o2[1]) ? -1 : ((o1[1] == o2[1]) ? 0 : 1);
            }
        });

        int count = 1;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] < end) {
                continue;
            }
            end = intervals[i][1];
            count++;
        }

        return intervals.length - count;
    }

}
