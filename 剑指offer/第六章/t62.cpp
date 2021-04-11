
// 2021.04.11
// 剑指offer 第61题
// https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
#include <iostream>

class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        if (n < 1 || m < 1)
        {
            return -1;
        }

        int last = 0;
        for (int i = 2; i <= n; i++)
        {
            last = (last + m) % i;
        }
        
        return last;
    }
};