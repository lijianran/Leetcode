
// 2021.05.28
// Leetcode 第 477 题
// https://leetcode-cn.com/problems/total-hamming-distance/
#include <iostream>
#include <vector>
using std::vector;

// 暴力 超时
// class Solution
// {
// public:
//     int totalHammingDistance(vector<int> &nums)
//     {
//         if (nums.size() == 0)
//         {
//             return 0;
//         }

//         int total = 0;
//         for (int i = 0; i < nums.size() - 1; i++)
//         {
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 if (nums[i] == nums[j])
//                 {
//                     continue;
//                 }
//                 total += hammingDistance(nums[i], nums[j]);
//             }
//         }
//         return total;
//     }

// private:
//     int hammingDistance(int x, int y)
//     {
//         int z = x ^ y;
//         int sum = 0;
//         while (z != 0)
//         {
//             sum += z & 1;
//             z = z >> 1;
//         }
//         return sum;
//     }
// };

/*
总结
1.  思路是:
    比如有3个数(用二进制表示) (方向从右到左<-，分别为第1位、第2位...)
        第一个数 a: 1 0 0 1
        第二个数 b: 0 1 1 1
        第三个数 c: 0 0 1 1
    那么第一位上的汉明距离总和是0。
        为什么？ 因为a、b、c该位全是"1"，任意两个"1"的汉明距离是0，所以该位汉明距离总和是0。
    接下来看第二位，a的第二位是"0"，b、c的是"1"，此时该位的汉明距离就是2。
        为什么？ 由上面我们可以得到，该位的"0"有1个，"1"有2个，而任意一个"0"都可以和任意一个"1"组合，
                    一对组合可以产生的汉明距离为1，所以问题转换为了算多少对01组合，那么怎么计算呢？
                    答案就是该位"0"的个数乘以"1"的个数。
    接下来看第三位，可以看出，此时"0"有2个，"1"有1个，所以可以产生的汉明距离为2。
    接下来看第四位，可以看出，此时"0"有2个，"1"有1个，所以可以产生的汉明距离为2。
    于是: 总的汉明距离就是 0 + 2 + 2 + 2 = 6
*/

class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int total = 0;
        // for (int i = 0; i < 32; i++)
        for (int i = 0; i < 31; i++) // 31 位，32 位代表符号
        {
            int count0 = 0;
            int count1 = 0;
            for (int num : nums)
            {
                num = num >> i;
                int bit = num & 1;
                if (bit == 0)
                {
                    count0 += 1;
                }
                else
                {
                    count1 += 1;
                }
            }
            total += count0 * count1;
        }

        return total;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {4, 14, 2};

    std::cout << solution.totalHammingDistance(nums) << std::endl;

    return 0;
}
