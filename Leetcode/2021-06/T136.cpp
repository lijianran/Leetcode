
// 2021.06.10
// Leetcode 第 136 题
// https://leetcode-cn.com/problems/single-number/

#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        for (const int &num : nums)
        {
            ret ^= num;
        }
        return ret;
    }
};
