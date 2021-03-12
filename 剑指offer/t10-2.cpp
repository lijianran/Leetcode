
// 2021.03.12
// 剑指offer 第10题(2)
// https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
#include <iostream>
using namespace std;

class Solution
{
public:
    int numWays(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }

        long long one = 1;
        long long two = 2;
        long long num = 0;
        for (int i = 3; i <= n; i++)
        {
            num = (one + two) % 1000000007;

            one = two;
            two = num;
        }

        return num;
    }
};

int main()
{
    Solution solution;

    cout << solution.numWays(99) << endl;

    return 0;
}