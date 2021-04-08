
// 2021.04.08
// 剑指offer 第51题
// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int length = nums.size();
        if (length == 0 || length == 1)
        {
            return 0;
        }

        vector<int> copy(nums);

        int count = InversePairsCore(nums, copy, 0, length - 1);

        return count;
    }

    int InversePairsCore(vector<int> &nums, vector<int> &copy, int start, int end)
    {
        if (start == end)
        {
            copy[start] = nums[start];
            return 0;
        }

        int length = (end - start) / 2;

        int left = InversePairsCore(copy, nums, start, start + length);
        int right = InversePairsCore(copy, nums, start + length + 1, end);

        int i = start + length;
        int j = end;
        int indexCopy = end;
        int count = 0;
        while (i >= start && j >= start + length + 1)
        {
            if (nums[i] > nums[j])
            {
                copy[indexCopy--] = nums[i--];
                count += j - start - length;
            }
            else
            {
                copy[indexCopy--] = nums[j--];
            }
        }

        for (; i >= start; --i)
        {
            copy[indexCopy--] = nums[i];
        }

        for (; j >= start + length + 1; --j)
        {
            copy[indexCopy--] = nums[j];
        }

        return left + right + count;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test1 = {7, 5, 6, 4};
    vector<int> test2 = {1, 2, 1, 2, 1};

    // std::cout << solution.reversePairs(test1) << std::endl;
    std::cout << solution.reversePairs(test2) << std::endl;
    return 0;
}
