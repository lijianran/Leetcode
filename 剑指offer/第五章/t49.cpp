
// 2021.04.06
// 剑指offer 第49题
// https://leetcode-cn.com/problems/chou-shu-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1;
        int nextUglyIndex = 1;

        int pMultiply2 = 0;
        int pMultiply3 = 0;
        int pMultiply5 = 0;

        while (nextUglyIndex < n)
        {
            int min = Min(uglyNumbers[pMultiply2] * 2, uglyNumbers[pMultiply3] * 3, uglyNumbers[pMultiply5] * 5);
            uglyNumbers[nextUglyIndex] = min;

            while (uglyNumbers[pMultiply2] * 2 <= uglyNumbers[nextUglyIndex])
            {
                ++pMultiply2;
            }
            while (uglyNumbers[pMultiply3] * 3 <= uglyNumbers[nextUglyIndex])
            {
                ++pMultiply3;
            }
            while (uglyNumbers[pMultiply5] * 5 <= uglyNumbers[nextUglyIndex])
            {
                ++pMultiply5;
            }

            ++nextUglyIndex;
        }

        int result = uglyNumbers[nextUglyIndex - 1];
        return result;
    }

    int Min(int num1, int num2, int num3)
    {
        int min = (num1 < num2) ? num1 : num2;
        min = (min < num3) ? min : num3;
        return min;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::cout << solution.nthUglyNumber(0) << std::endl;
    return 0;
}
