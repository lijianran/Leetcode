
// 2021.05.31
// Leetcode 第 342 题
// https://leetcode-cn.com/problems/power-of-four/

#include <iostream>

// 位运算
// class Solution
// {
// public:
//     bool isPowerOfFour(int n)
//     {
//         if (n <= 0)
//         {
//             return false;
//         }
//         int mark = 0;
//         int sum = 0;
//         for (int i = 1; i < 32; ++i)
//         {
//             if (n & 1)
//             {
//                 mark = i;
//                 ++sum;
//                 if (sum > 1)
//                 {
//                     return false;
//                 }
//             }
//             n = n >> 1;
//         }

//         return (sum == 1) && (mark % 2 == 1);
//     }
// };

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 1)
        {
            return true;
        }
        if (n < 4)
        {
            return false;
        }
        if ((n & (n - 1)) != 0)
        {
            // 判断是否只有一个 1
            return false;
        }
        // 判断是否在奇数位
        return ((n & 0x55555555) == n);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::cout << solution.isPowerOfFour(20) << std::endl;

    return 0;
}