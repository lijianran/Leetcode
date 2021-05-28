
// 2021.05.28
// Leetcode 第 4 题
// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>
using std::vector;

// 双指针
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int sum = m + n;

        if (sum % 2 == 0)
        {
            // 偶数
            int i = 0;
            int j = 0;
            // 维护两个值
            int temp[2];
            while (i < m && j < n)
            {
                if (nums1[i] < nums2[j])
                {
                    temp[0] = temp[1];
                    temp[1] = nums1[i];
                    i++;
                }
                else
                {
                    temp[0] = temp[1];
                    temp[1] = nums2[j];
                    j++;
                }

                // 合并数组中已经有了 i + j 个数，且等于 sum / 2 + 1
                if (i + j == sum / 2 + 1)
                {
                    return (double)(temp[0] + temp[1]) / 2;
                }
            }

            // nums1 已经取完了数，还没有 return 结果
            if (i >= m)
            {
                // 如果已经有了 sum/2 个数
                if (i + j == sum / 2)
                {
                    // 返回 nums1 的最后一个数和 nums2 的第 sum/2 - m 个数
                    return (double)(nums1[m - 1] + nums2[sum / 2 - m]) / 2;
                }
                // 结果在 nums2 中
                return (double)(nums2[sum / 2 - m] + nums2[sum / 2 - m - 1]) / 2;
            }

            // nums2 已经取完了数，还没有 return 结果
            if (j >= n)
            {
                // 如果已经有了 sum/2 个数
                if (i + j == sum / 2)
                {
                    // 返回 nums2 的最后一个数和 nums1 的第 sum/2 - n 个数
                    return (double)(nums2[n - 1] + nums1[sum / 2 - n]) / 2;
                }
                // 结果在 nums1 中
                return (double)(nums1[sum / 2 - n] + nums1[sum / 2 - n - 1]) / 2;
            }
        }
        else
        {
            int i = 0;
            int j = 0;
            int temp;
            while (i < m && j < n)
            {

                if (nums1[i] < nums2[j])
                {
                    temp = nums1[i];
                    i++;
                }
                else
                {
                    temp = nums2[j];
                    j++;
                }

                if (i + j == sum / 2 + 1)
                {
                    return (double)temp;
                }
            }

            if (i >= m)
            {
                return (double)nums2[sum / 2 - m];
            }
            if (j >= n)
            {
                return (double)nums1[sum / 2 - n];
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    // vector<int> nums1 = {1, 3};
    // vector<int> nums2 = {2};

    // vector<int> nums1 = {1, 2};
    // vector<int> nums2 = {3, 4};

    // vector<int> nums1 = {0, 0};
    // vector<int> nums2 = {0, 0};

    vector<int> nums1 = {2};
    vector<int> nums2 = {1};

    // vector<int> nums1 = {0, 0, 0, 0, 0};
    // vector<int> nums2 = {-1, 0, 0, 0, 0, 0, 1};

    std::cout << solution.findMedianSortedArrays(nums1, nums2) << std::endl;

    return 0;
}
