
// 2021.04.11
// 剑指offer 第62题
// https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int length = prices.size();
        if (length < 2)
        {
            return 0;
        }

        int min = prices[0];
        int maxDiff = prices[1] - min;

        for (int i = 2; i < length; i++)
        {
            if (prices[i - 1] < min)
            {
                min = prices[i - 1];
            }

            int currentDiff = prices[i] - min;
            if (currentDiff > maxDiff)
            {
                maxDiff = currentDiff;
            }
        }

        return (maxDiff >= 0) ? maxDiff : 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test1 = {7, 1, 5, 3, 6, 4};
    vector<int> test2 = {7, 6, 4, 3, 1};

    std::cout << solution.maxProfit(test2) << std::endl;
    return 0;
}
