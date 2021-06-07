
// 2021.06.07
// Leetcode 第 56 题
// https://leetcode-cn.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
        {
            return intervals;
        }

        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> merged;
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= merged.back()[1])
            {
                merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
            }
            else
            {
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;
    }
};
