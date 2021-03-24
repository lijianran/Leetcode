
// 2021.03.12
// 剑指offer 第10题(1)
// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
#include <iostream>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }

        long long one = 0;
        long long two = 1;
        long long fibNum = 0;
        for (int i = 2; i <= n; i++)
        {
            fibNum = (one + two) % 1000000007;

            one = two;
            two = fibNum;
        }

        return fibNum;
    }
};

int main()
{
    Solution solution;

    cout << solution.fib(99) << endl;

    return 0;
}