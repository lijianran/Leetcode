
// 2021.04.09
// 剑指offer 第53题(1)
// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int result = 0;
        int length = nums.size();
        if (length > 0)
        {
            int first = getFirstK(nums, length, target, 0, length - 1);
            int last = getLastK(nums, length, target, 0, length - 1);

            if (first > -1 && last >= -1)
            {
                result = last - first + 1;
            }
        }
        return result;
    }

    int getFirstK(vector<int> &nums, int length, int k, int start, int end)
    {
        if (start > end)
        {
            return -1;
        }

        int middleIndex = (start + end) / 2;
        int middleData = nums[middleIndex];

        if (middleData == k)
        {
            if ((middleIndex > 0 && nums[middleIndex - 1] != k) || middleIndex == 0)
            {
                return middleIndex;
            }
            else
            {
                end = middleIndex - 1;
            }
        }
        else if (middleData > k)
        {
            end = middleIndex - 1;
        }
        else
        {
            start = middleIndex + 1;
        }

        return getFirstK(nums, length, k, start, end);
    }

    int getLastK(vector<int> &nums, int length, int k, int start, int end)
    {
        if (start > end)
        {
            return -1;
        }

        int middleIndex = (start + end) / 2;
        int middleData = nums[middleIndex];

        if (middleData == k)
        {
            if ((middleIndex < length - 1 && nums[middleIndex + 1] != k) || middleIndex == length - 1)
            {
                return middleIndex;
            }
            else
            {
                start = middleIndex + 1;
            }
        }
        else if (middleData < k)
        {
            start = middleIndex + 1;
        }
        else
        {
            end = middleIndex - 1;
        }

        return getLastK(nums, length, k, start, end);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test1 = {5, 7, 7, 8, 8, 10};

    std::cout << solution.search(test1, 7) << std::endl;

    return 0;
}
