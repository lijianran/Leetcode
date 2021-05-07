
// 2021.05.07
// Leetcode 第406题
// https://leetcode-cn.com/problems/queue-reconstruction-by-height/description/
package Greed;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class T406 {
    public static void main(String[] args) {

    }

    public int[][] reconstructQueue(int[][] people) {
        if (people == null || people.length == 0) {
            return new int[][] {};
        }

        Arrays.sort(people, (a, b) -> (a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]));

        List<int[]> queue = new ArrayList<>();
        for (int[] p : people) {
            queue.add(p[1], p);
        }

        return queue.toArray(new int[queue.size()][]);
    }
}
