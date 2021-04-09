
// 2021.04.09
// 剑指offer 第56题(2)
// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int length = nums.size();

        if (length <= 0)
        {
            return -1;
        }

        int bitSum[32] = {0};
        for (int i = 0; i < length; i++)
        {
            int bitMask = 1;
            for (int j = 31; j >= 0; --j)
            {
                int bit = nums[i] & bitMask;
                if (bit)
                {
                    bitSum[j] += 1;
                }
                bitMask = bitMask << 1;
            }
        }

        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            result = result << 1;
            result += bitSum[i] % 3;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test1 = {3, 4, 3, 3};
    vector<int> test2 = {9, 1, 7, 9, 7, 9, 7};

    std::cout << solution.singleNumber(test1) << std::endl;
    return 0;
}
