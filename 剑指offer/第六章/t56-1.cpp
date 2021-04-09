
// 2021.04.09
// 剑指offer 第56题(1)
// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int length = nums.size();
        if (length <= 2)
        {
            return nums;
        }

        int resultExclusiveOR = 0;
        for (int i = 0; i < length; i++)
        {
            resultExclusiveOR ^= nums[i];
        }

        unsigned int indexOf1 = findFirstBitIs1(resultExclusiveOR);

        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < length; i++)
        {
            if (isBit1(nums[i], indexOf1))
            {
                num1 ^= nums[i];
            }
            else
            {
                num2 ^= nums[i];
            }
        }

        vector<int> result;
        result.push_back(num1);
        result.push_back(num2);

        return result;
    }

    unsigned int findFirstBitIs1(int num)
    {
        int indexOfBit = 0;
        int a = num & 1;
        while (((num & 1) == 0) && (indexOfBit < 8 * sizeof(int)))
        {
            num = num >> 1;
            ++indexOfBit;
        }

        return indexOfBit;
    }

    bool isBit1(int num, unsigned int indexBit)
    {
        num = num >> indexBit;
        return (num & 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test1 = {4, 1, 4, 6};
    vector<int> test2 = {1, 2, 10, 4, 1, 4, 3, 3};

    vector<int> result = solution.singleNumbers(test2);

    return 0;
}
