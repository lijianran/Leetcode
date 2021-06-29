
// 2021.06.29
// Leetcode 第 338 题
// https://leetcode-cn.com/problems/counting-bits/

#include <iostream>
#include <vector>
using std::vector;

// x & (x−1)   该运算将 x 的二进制表示的最后一个 1 变成 0
class Solution
{
public:
    vector<int> countBits(int n)
    {
        std::vector<int> bits(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            bits[i] = bits[i & (i - 1)] + 1;
        }
        return bits;
    }
};
