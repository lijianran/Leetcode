
// 2021.05.10
// Leetcode 第122题
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/
package Greed;

public class T122 {
    public static void main(String[] args) {
        int[] prices = { 7, 1, 5, 3, 6, 4 };
        int[] prices2 = { 7, 6, 4, 3, 1 };
        int[] prices3 = { 1, 2, 3, 4, 5 };

        T122 solution = new T122();
        System.out.println(solution.maxProfit(prices));
        System.out.println(solution.maxProfit(prices2));
        System.out.println(solution.maxProfit(prices3));
    }

    public int maxProfit(int[] prices) {
        int profit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += (prices[i] - prices[i - 1]);
            }
        }

        return profit;
    }
}
