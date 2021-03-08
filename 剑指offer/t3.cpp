
// 2021.03.07
// 剑指offer 第3题
// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        // 判断长度
        int length = nums.size();
        if (length <= 0)
        {
            return -1;
        }

        // 判断输入是否合法
        for (int i = 0; i < length; i++)
        {
            if (nums[i] < 0 || nums[i] > length - 1)
            {
                return -1;
            }
        }

        // 查找重复数字
        for (int i = 0; i < length; i++)
        {
            while (nums[i] != i)
            {
                if (nums[i] == nums[nums[i]])
                {
                    return nums[i];
                }

                // 互换
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    vector<int> nums1 = {1, 2, 3, 4, 3, 5};
    vector<int> nums2;


    Solution solution;

    cout << "test output:" << endl;
    cout << solution.findRepeatNumber(nums) << endl;
}