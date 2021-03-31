
// 2021.03.31
// 剑指offer 第42题
// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int length = nums.size();
        if (length <= 0)
        {
            return 0;
        }

        int sum = nums[0];
        int greatestSum = sum;
        for (int i = 1; i < length; i++)
        {
            if (sum <= 0)
            {
                sum = nums[i];
            }
            else
            {
                sum += nums[i];
            }

            if (sum > greatestSum)
            {
                greatestSum = sum;
            }
        }

        return greatestSum;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> test2 = {1, -2, 3, 10, -4, 7, 2, -5};

    std::cout << solution.maxSubArray(test1) << std::endl;
    std::cout << solution.maxSubArray(test2) << std::endl;

    return 0;
}
