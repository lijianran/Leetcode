
// 2021.06.15
// Leetcode 第 169 题
// https://leetcode-cn.com/problems/majority-element/

#include <iostream>
#include <vector>
using std::vector;

// 摩尔投票法
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ret = nums[0];
        int count = 0;
        for (int &num : nums)
        {
            if (num == ret)
            {
                ++count;
            }
            else if (--count < 0)
            {
                ret = num;
                count = 1;
            }
        }
        return ret;
    }
};
