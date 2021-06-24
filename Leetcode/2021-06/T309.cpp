
// 2021.06.24
// Leetcode 第 309 题
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        int n = prices.size();
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        // f[i][0]: 手上持有股票的最大收益
        // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        for (int i = 0; i < n; ++i)
        {
            // 可以是前一天已经有的股票，或者第 i 天新买的股票
            int newf0 = std::max(f0, f2 - prices[i]);
            // 处于冷冻期，说明第 i 天卖出了股票
            int newf1 = f0 + prices[i];
            // 第 i 天结束后没有股票在手，说明当天没有进行任何操作，即第 i−1 天时不持有任何股票
            int newf2 = std::max(f1, f2);

            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }
        return std::max(f1, f2);
    }
};
