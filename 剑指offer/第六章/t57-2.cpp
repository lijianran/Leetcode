
// 2021.04.10
// 剑指offer 第57题(2)
// https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        if (target < 3)
        {
            return {};
        }
        int small = 1;
        int big = 2;
        int middle = (1 + target) / 2;
        int curSum = small + big;

        vector<vector<int>> result;
        while (small < middle)
        {
            if (curSum == target)
            {
                printResult(result, small, big);
            }

            while (curSum > target && small < middle)
            {
                curSum -= small;
                small++;

                if (curSum == target)
                {
                    printResult(result, small, big);
                }
            }

            big++;
            curSum += big;
        }

        return result;
    }

    void printResult(vector<vector<int>> &result, int small, int big)
    {
        vector<int> oneResult;
        for (int i = small; i <= big; i++)
        {
            oneResult.push_back(i);
        }
        result.push_back(oneResult);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    vector<vector<int>> result = solution.findContinuousSequence(15);
    return 0;
}
