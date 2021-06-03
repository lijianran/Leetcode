
// 2021.06.03
// Leetcode 第 23 题
// https://leetcode-cn.com/problems/merge-k-sorted-lists/

#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

// 题解：https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            --i;
        }
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j])
            {
                --j;
            }
            std::swap(nums[i], nums[j]);
        }

        std::reverse(nums.begin() + i + 1, nums.end());
    }
};
