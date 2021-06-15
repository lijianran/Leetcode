
// 2021.06.15
// Leetcode 第 152 题
// https://leetcode-cn.com/problems/maximum-product-subarray/

#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        std::vector<int> maxF(nums);
        std::vector<int> minF(nums);
        for (int i = 1; i < nums.size(); ++i)
        {
            maxF[i] = std::max(maxF[i - 1] * nums[i], std::max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = std::min(minF[i - 1] * nums[i], std::min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *std::max_element(maxF.begin(), maxF.end());
    }
};

class Solution1
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxF = nums[0];
        int minF = nums[0];
        int ret = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int mx = maxF;
            int mn = minF;
            maxF = std::max(mx * nums[i], std::max(nums[i], mn * nums[i]));
            minF = std::min(mn * nums[i], std::min(nums[i], mx * nums[i]));
            ret = std::max(maxF, ret);
        }
        return ret;
    }
};
