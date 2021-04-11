
// 2021.04.11
// 剑指offer 第60题
// https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
#include <iostream>
#include <vector>
#include <cmath>
using std::vector;

class Solution
{
public:
    vector<double> dicesProbability(int n)
    {
        if (n < 1)
        {
            return {0.16667, 0.16667, 0.16667, 0.16667, 0.16667, 0.16667};
        }

        vector<vector<int>> probability(2, vector<int>(6 * n + 1));

        int flag = 0;
        for (int i = 1; i <= 6; i++)
        {
            probability[flag][i] = 1;
        }

        for (int k = 2; k <= n; k++)
        {
            for (int i = 0; i < k; i++)
            {
                probability[1 - flag][i] = 0;
            }

            for (int i = k; i <= 6 * n; i++)
            {
                probability[1 - flag][i] = 0;
                for (int j = 1; j <= i && j <= 6; j++)
                {
                    probability[1 - flag][i] += probability[flag][i - j];
                }
            }

            flag = 1 - flag;
        }

        vector<double> result;
        double total = std::pow(6.0, n);
        for (int i = n; i <= 6 * n; i++)
        {
            result.push_back((double)probability[flag][i] / total);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    
    vector<double> result = solution.dicesProbability(2);
    return 0;
}
