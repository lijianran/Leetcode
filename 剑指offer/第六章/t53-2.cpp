
// 2021.04.09
// 剑指offer 第53题(2)
// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int length = nums.size();
        if (length <= 0)
        {
            return -1;
        }

        int left = 0;
        int right = length - 1;
        while (left <= right)
        {
            int middle = (right + left) >> 1;
            if (nums[middle] != middle)
            {
                if (middle == 0 || nums[middle - 1] == middle - 1)
                {
                    return middle;
                }
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        if (left == length)
        {
            return length;
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test1 = {0, 1, 3};
    vector<int> test2 = {0, 1, 2, 3, 4, 5, 6, 7, 9};

    std::cout << solution.missingNumber(test1) << std::endl;
    std::cout << solution.missingNumber(test2) << std::endl;

    return 0;
}
