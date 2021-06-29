
// 2021.06.29
// Leetcode 第 322 题
// https://leetcode-cn.com/problems/coin-change/

#include <iostream>
#include <vector>
using std::vector;

// 记忆化搜索 dp
class Solution
{
private:
    std::vector<int> count;

    int dp(std::vector<int> &coins, int remain)
    {
        if (remain < 0)
            return -1;
        if (remain == 0)
            return 0;
        if (count[remain - 1] != 0)
            return count[remain - 1];
        int Min = __INT_MAX__;
        for (int coin : coins)
        {
            int res = dp(coins, remain - coin);
            if (res >= 0 && res < Min)
            {
                Min = res + 1;
            }
        }
        count[remain - 1] = (Min == __INT_MAX__ ? -1 : Min);
        return count[remain - 1];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount < 1)
            return 0;
        count.resize(amount);
        return dp(coins, amount);
    }
};

// dp
class Solution1
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int Max = amount + 1;
        std::vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i < amount; ++i)
        {
            for (int coin : coins)
            {
                if (coin <= i)
                {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return (dp[amount] > amount ? -1 : dp[amount]);
    }
};
