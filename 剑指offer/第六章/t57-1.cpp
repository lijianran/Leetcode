
// 2021.04.10
// 剑指offer 第57题(1)
// https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int length = nums.size();
        if (length == 1)
        {
            return {};
        }
        if (length == 2)
        {
            if (nums[0] + nums[1] == target)
            {
                return nums;
            }
            else
            {
                return {};
            }
        }

        int ahead = 0;
        int behind = length - 1;
        while (ahead < behind)
        {
            long long curSum = nums[ahead] + nums[behind];

            if (curSum == target)
            {
                return {nums[ahead], nums[behind]};
            }
            else if (curSum > target)
            {
                behind--;
            }
            else
            {
                ahead++;
            }
        }

        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test1 = {2, 7, 11, 15};
    vector<int> test2 = {10, 26, 30, 31, 47, 60};
    vector<int> test3;

    vector<int> result = solution.twoSum(test3, 40);

    return 0;
}
