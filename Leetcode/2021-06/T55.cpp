
// 2021.06.07
// Leetcode 第 55 题
// https://leetcode-cn.com/problems/jump-game/

#include <iostream>
#include <vector>
using std::vector;

// 贪心
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int length = nums.size();
        if (length < 2)
        {
            return true;
        }

        int rightmost = 0;
        for (int i = 0; i < length; ++i)
        {
            if (i <= rightmost)
            {
                rightmost = std::max(rightmost, i + nums[i]);
                if (rightmost >= length - 1)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::vector<int> nums = {3, 2, 1, 0, 4};
    std::cout << solution.canJump(nums) << std::endl;
    return 0;
}
