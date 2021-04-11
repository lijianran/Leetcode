
// 2021.04.11
// 剑指offer 第61题
// https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        int length = nums.size();
        if (length < 1)
        {
            return false;
        }

        std::sort(nums.begin(), nums.end());

        int numberOfZero = 0;
        int numberOfGap = 0;

        for (int i = 0; i < length && nums[i] == 0; i++)
        {
            ++numberOfZero;
        }

        int small = numberOfZero;
        int big = small + 1;
        while (big < length)
        {
            if (nums[small] == nums[big])
            {
                return false;
            }

            numberOfGap += nums[big] - nums[small] - 1;
            small = big;
            big++;
        }

        return (numberOfGap > numberOfZero) ? false : true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test1 = {1, 2, 4, 3, 5};
    vector<int> test2 = {0, 6, 1, 2, 5};
    std::cout << solution.isStraight(test2) << std::endl;
    return 0;
}
