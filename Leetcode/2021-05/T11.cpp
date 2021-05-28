
// 2021.05.28
// Leetcode 第 11 题
// https://leetcode-cn.com/problems/container-with-most-water/

#include <iostream>
#include <vector>
using std::vector;

// 暴力 O(n^2) 超时
// class Solution
// {
// public:
//     int maxArea(vector<int> &height)
//     {
//         int max = 0;
//         for (size_t i = 0; i < height.size() - 1; ++i)
//         {
//             for (size_t j = i + 1; j < height.size(); ++j)
//             {
//                 int diff = j - i;
//                 int h = height[i] < height[j] ? height[i] : height[j];
//                 int area = diff * h;
//                 if (area > max)
//                 {
//                     max = area;
//                 }
//             }
//         }
//         return max;
//     }
// };

// 双指针
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            int h = height[i] < height[j] ? height[i] : height[j];
            int area = (j - i) * h;
            if (area > max)
            {
                max = area;
            }

            if (height[i] < height[j])
            {
                ++i;
            }
            else
            {
                --j;
            }
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    // vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> nums = {1, 1};

    std::cout << solution.maxArea(nums) << std::endl;

    return 0;
}