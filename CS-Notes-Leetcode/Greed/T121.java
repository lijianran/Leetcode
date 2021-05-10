
// 2021.05.10
// Leetcode 第121题
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/description/
package Greed;

public class T121 {
    public static void main(String[] args) {
        int[] prices = { 7, 1, 5, 3, 6, 4 };
        int[] prices2 = { 7, 6, 4, 3, 1 };

        T121 solution = new T121();
        System.out.println(solution.maxProfit(prices));
        System.out.println(solution.maxProfit(prices2));
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        if (n == 0) {
            return 0;
        }
        int soFarMin = prices[0];
        int max = 0;
        for (int i = 1; i < n; i++) {
            if (soFarMin > prices[i]) {
                soFarMin = prices[i];
            } else {
                max = Math.max(max, prices[i] - soFarMin);
            }
        }

        return max;
    }
}
