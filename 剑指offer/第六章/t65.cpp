
// 2021.04.12
// 剑指offer 第65题
// https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
#include <iostream>

class Solution
{
public:
    int add(int a, int b)
    {
        int sum;
        int carry;
        do
        {
            sum = a ^ b;
            carry = ((unsigned int)(a & b) << 1);
            // carry = (a & b) << 1;

            a = sum;
            b = carry;
        } while (b);

        return a;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::cout << solution.add(12, 321) << std::endl;
    return 0;
}
