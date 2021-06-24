
// 2021.06.24
// Leetcode 第 238 题
// https://leetcode-cn.com/problems/product-of-array-except-self/

#include <iostream>
#include <vector>
using std::vector;

/*
原数组：       [1       2       3       4]
左部分的乘积：   1       1      1*2    1*2*3
右部分的乘积： 2*3*4    3*4      4      1
结果：        1*2*3*4  1*3*4   1*2*4  1*2*3*1
*/
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        int left = 1;
        int right = 1;
        std::vector<int> ret(n, 1);
        for (int i = 0; i < n; ++i)
        {
            ret[i] *= left;
            left *= nums[i];

            ret[n - i - 1] *= right;
            right *= nums[n - i - 1];
        }
        return ret;
    }
};
