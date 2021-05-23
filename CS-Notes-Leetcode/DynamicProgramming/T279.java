
// 2021.05.23
// Leetcode 第 279 题
// https://leetcode-cn.com/problems/perfect-squares/description/
package DynamicProgramming;

import java.util.ArrayList;
import java.util.List;

public class T279 {
    public static void main(String[] args) {
        T279 solution = new T279();
        System.out.println(solution.numSquares(12));
        System.out.println(solution.numSquares(13));
    }

    public int numSquares(int n) {
        List<Integer> squareList = generateSquareList(n);
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int min = Integer.MAX_VALUE;
            for (int square : squareList) {
                if (square > i) {
                    break;
                }
                min = Math.min(min, dp[i - square] + 1);
            }
            dp[i] = min;
        }
        return dp[n];
    }

    private List<Integer> generateSquareList(int n) {
        List<Integer> squareList = new ArrayList<>();
        int diff = 3;
        int sqare = 1;
        while (sqare <= n) {
            squareList.add(sqare);
            sqare += diff;
            diff += 2;
        }
        return squareList;
    }
}
