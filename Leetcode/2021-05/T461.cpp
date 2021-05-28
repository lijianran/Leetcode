
// 2021.05.27
// Leetcode 第 461 题
// https://leetcode-cn.com/problems/hamming-distance/
#include <iostream>

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int z = x ^ y;
        int sum = 0;
        while (z != 0)
        {
            sum += z & 1;
            z = z >> 1;
        }
        return sum;
    }

};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::cout << solution.hammingDistance(1, 4) << std::endl;

    return 0;
}
