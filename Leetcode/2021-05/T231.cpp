
// 2021.05.30
// Leetcode 第 231 题
// https://leetcode-cn.com/problems/power-of-two/

#include <iostream>

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        bool flag = false;
        // for (int i = 0; i < 32; ++i)
        while (n != 0)
        {
            if (n & 1)
            {
                if (flag)
                {
                    return false;
                }
                flag = true;
            }
            n = n >> 1;
        }

        return flag;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    // std::cout << solution.isPowerOfTwo(1) << std::endl;
    // std::cout << solution.isPowerOfTwo(2) << std::endl;
    // std::cout << solution.isPowerOfTwo(4) << std::endl;
    std::cout << solution.isPowerOfTwo(-2147483646) << std::endl;
    std::cout << solution.isPowerOfTwo(-2147483648) << std::endl;

    return 0;
}
