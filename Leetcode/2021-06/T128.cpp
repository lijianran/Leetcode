
// 2021.06.10
// Leetcode 第 128 题
// https://leetcode-cn.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <vector>
#include <unordered_set>
using std::vector;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int max = 0;
        // 去重
        std::unordered_set<int> set;
        for (const int &num : nums)
        {
            set.insert(num);
        }
        // 遍历 set
        for (const int &num : set)
        {
            // 如果 num - 1 有，跳过
            if (!set.count(num - 1))
            {
                int currentNum = num;
                int length = 1;
                // num - 1 不存在，从 num 开始 ++
                while (set.count(currentNum + 1))
                {
                    ++currentNum;
                    ++length;
                }
                max = std::max(length, max);
            }
        }
        return max;
    }
};
