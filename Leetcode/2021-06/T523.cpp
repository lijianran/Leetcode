
// 2021.06.02
// Leetcode 第 523 题
// https://leetcode-cn.com/problems/continuous-subarray-sum/

#include <iostream>
#include <vector>
#include <unordered_map>
using std::vector;

// 前缀和  数学
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int length = nums.size();
        if (length < 2)
        {
            return false;
        }
        std::unordered_map<int, int> map;
        map[0] = -1;
        int temp = 0;
        for (size_t i = 0; i < length; ++i)
        {
            temp = (temp + nums[i]) % k;
            if (map.count(temp))
            {
                int preIndex = map[temp];
                if (i - preIndex >= 2)
                {
                    return true;
                }
            }
            else
            {
                map[temp] = i;
            }
        }
        return false;
    }
};