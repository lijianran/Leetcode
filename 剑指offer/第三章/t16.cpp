
// 2021.03.16
// 剑指offer 第16题
// https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0 && n < 0)
        {
            return 0.0;
        }
        if (x == 1)
        {
            return 1.0;
        }

        unsigned int absn;
        if (n < 0)
        {
            absn = (unsigned int)(-n);
        }
        else
        {
            absn = (unsigned int)(n);
        }

        double result = myPowWithUnsignedN(x, absn);

        if (n < 0)
        {
            result = 1.0 / result;
        }

        return result;
    }

    double myPowWithUnsignedN(double x, unsigned int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }

        double result = myPowWithUnsignedN(x, n >> 1);
        result *= result;
        if (n & 0x1 == 1)
        {
            result *= x;
        }
        return result;

        // double result = 1.0;
        // for (int i = 0; i < n; i++)
        // {
        //     result *= x;
        // }
        // return result;
    }
};

class Solution1 {
public:
    double myPow(double x, int n) {
        double res=1;
        double base=x;
        bool flag=n>=0;
        //负数取反，考虑到最小负数，需要先自增，后续再除以2
        if(!flag) n=-(++n);
        while(n>0){
            if(n&1) res*=x;
            n=n>>1;
            x*=x;
        }
        return flag?res:1/(res*base);
    }
};

int main()
{
    Solution solution;
    Solution1 solution1;

    // cout << solution.myPow(2.0, 10) << endl;
    // cout << solution.myPow(2.1, 3) << endl;
    // cout << solution.myPow(2.0, -2) << endl;
    // cout << solution.myPow(1.00000, 2147483647) << endl;
    cout << solution.myPow(2.00000, -2147483648) << endl;
    cout << solution1.myPow(2.00000, -2147483648) << endl;

    return 0;
}