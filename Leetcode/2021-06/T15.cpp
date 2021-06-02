
// 2021.06.02
// Leetcode 第 15 题
// https://leetcode-cn.com/problems/3sum/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::vector;

// 结果无法去重
// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         int length = nums.size();
//         if (length < 3)
//         {
//             return {};
//         }

//         std::vector<std::vector<int>> ret;

//         for (int i = 0; i < length - 2; ++i)
//         {
//             std::unordered_map<int, int> hash;
//             int target = -nums[i];
//             for (int j = i + 1; j < length; ++j)
//             {
//                 if (hash.count(target - nums[j]) > 0)
//                 {
//                     std::vector<int> result{nums[i], nums[j], nums[hash[target - nums[j]]]};
//                     ret.push_back(result);
//                 }
//                 hash[nums[j]] = j;
//             }
//         }

//         return ret;
//     }
// };

// 排序后，双指针
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int length = nums.size();
        if (length < 3)
        {
            return {};
        }

        sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> ret;

        for (int first = 0; first < length; ++first)
        {
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int target = -nums[first];
            int third = length - 1;

            for (int second = first + 1; second < length; ++second)
            {
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }

                while (second < third && (nums[second] + nums[third]) > target)
                {
                    --third;
                }

                if (second == third)
                {
                    break;
                }

                if (nums[second] + nums[third] == target)
                {
                    ret.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ret;
    }
};

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) 
//     {
//         int size = nums.size();
//         if (size < 3)   return {};          // 特判
//         vector<vector<int> >res;            // 保存结果（所有不重复的三元组）
//         std::sort(nums.begin(), nums.end());// 排序（默认递增）
//         for (int i = 0; i < size; i++)      // 固定第一个数，转化为求两数之和
//         {
//             if (nums[i] > 0)    return res; // 第一个数大于 0，后面都是递增正数，不可能相加为零了
//             // 去重：如果此数已经选取过，跳过
//             if (i > 0 && nums[i] == nums[i-1])  continue;
//             // 双指针在nums[i]后面的区间中寻找和为0-nums[i]的另外两个数
//             int left = i + 1;
//             int right = size - 1;
//             while (left < right)
//             {
//                 if (nums[left] + nums[right] > -nums[i])
//                     right--;    // 两数之和太大，右指针左移
//                 else if (nums[left] + nums[right] < -nums[i])
//                     left++;     // 两数之和太小，左指针右移
//                 else
//                 {
//                     // 找到一个和为零的三元组，添加到结果中，左右指针内缩，继续寻找
//                     res.push_back(vector<int>{nums[i], nums[left], nums[right]});
//                     left++;
//                     right--;
//                     // 去重：第二个数和第三个数也不重复选取
//                     // 例如：[-4,1,1,1,2,3,3,3], i=0, left=1, right=5
//                     while (left < right && nums[left] == nums[left-1])  left++;
//                     while (left < right && nums[right] == nums[right+1])    right--;
//                 }
//             }
//         }
//         return res;
//     }
// };

int main(int argc, char const *argv[])
{
    Solution solution;
    std::vector<int> nums = {3, 0, -2, -1, 1, 2};
    auto ret = solution.threeSum(nums);
    return 0;
}
