
// 2021.05.28
// Leetcode 第 1 题
// https://leetcode-cn.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <map>
using std::vector;

// 暴力 O(n^2)
// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         for (int i = 0; i < nums.size() - 1; i++)
//         {
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 if (target == nums[i] + nums[j])
//                 {
//                     return {i, j};
//                 }
//             }
//         }

//         return {};
//     }
// };

// map 哈希表
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.count(target - nums[i]) > 0)
            {
                return {i, hash[target - nums[i]]};
            }
            hash[nums[i]] = i;
        }

        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> result = solution.twoSum(nums, 9);
    std::cout << result[0] << ',' << result[1] << std::endl;

    return 0;
}
