
// 2021.03.29
// 剑指offer 第39题
// https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int length = nums.size();
        int result = nums[0];
        int times = 1;

        for (int i = 1; i < length; i++)
        {
            if (times == 0)
            {
                result = nums[i];
                times = 1;
            }
            else if (nums[i] == result)
            {
                times++;
            }
            else
            {
                times--;
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> test1 = {1, 2, 3, 2, 2, 2, 5, 4, 2};

    std::cout << solution.majorityElement(test1) << std::endl;
    return 0;
}