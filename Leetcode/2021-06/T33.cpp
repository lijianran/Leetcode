
// 2021.06.04
// Leetcode 第 33 题
// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>
using std::vector;

// 时间复杂度 O(n)
// class Solution
// {
// public:
//     int search(vector<int> &nums, int target)
//     {
//         int length = nums.size();
//         int index = -1;
//         for (int i = 0; i < length - 1; ++i)
//         {
//             if (nums[i] > nums[i + 1])
//             {
//                 index = i;
//                 break;
//             }
//         }
//         int low = 0;
//         int high = index;
//         while (low <= high)
//         {
//             // int mid = (low + high) >> 1;
//             int mid = low + (high - low) >> 1;
//             if (nums[mid] == target)
//             {
//                 return mid;
//             }
//             else if (nums[mid] < target)
//             {
//                 low = mid + 1;
//             }
//             else
//             {
//                 high = mid - 1;
//             }
//         }
//         low = index + 1;
//         high = length - 1;
//         while (low <= high)
//         {
//             // int mid = (low + high) >> 1;
//             int mid = low + (high - low) >> 1;
//             if (nums[mid] == target)
//             {
//                 return mid;
//             }
//             else if (nums[mid] < target)
//             {
//                 low = mid + 1;
//             }
//             else
//             {
//                 high = mid - 1;
//             }
//         }
//         return -1;
//     }
// };

// O(log(n))
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] < nums[0])
            {
                // mid 后半部分递增有序
                if (target > nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else
            {
                // mid 前半部分递增有序
                if (target < nums[mid] && target >= nums[low])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << solution.search(nums, 0) << std::endl;
    return 0;
}
