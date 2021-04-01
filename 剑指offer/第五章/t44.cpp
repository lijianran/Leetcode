
// 2021.04.01
// 剑指offer 第44题
// https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/comments/
#include <iostream>
#include <cmath>

class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n < 0)
        {
            return -1;
        }

        int digits = 1;
        while (true)
        {
            int numbers = countOfIntegers(digits);
            if (n < numbers * digits)
            {
                return digitAtIndex(n, digits);
            }

            n -= digits * numbers;
            digits++;
        }
        return -1;
    }

    int countOfIntegers(int digits)
    {
        if (digits == 1)
        {
            return 10;
        }

        int count = (int)std::pow(10, digits - 1);
        return 9 * count;
    }

    int digitAtIndex(int n, int digits)
    {
        int number = beginNumber(digits) + n / digits;
        int indexFromRight = digits - n % digits;
        for (int i = 1; i < indexFromRight; i++)
        {
            number /= 10;
        }
        return number % 10;
    }

    int beginNumber(int digits)
    {
        if (digits == 1)
        {
            return 0;
        }

        return (int)std::pow(10, digits - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::cout << solution.findNthDigit(1000000000) << std::endl;
    return 0;
}
