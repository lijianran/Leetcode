
// 2021.03.15
// 剑指offer 第14题(2)
// https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        if (n == 3)
        {
            return 2;
        }

        int timesOf3 = n / 3;
        if (n - timesOf3 * 3 == 1)
        {
            timesOf3 -= 1;
        }

        int timesOf2 = (n - timesOf3 * 3) / 2;

        return ((powMod(3, timesOf3)) * (powMod(2, timesOf2))) % 1000000007;
    }

    long powMod(long x, long y)
    {
        if (y == 0)
            return 1;
        if (y == 1)
            return x;
        long t = powMod(x, y / 2) % 1000000007;
        return (y % 2) ? (x * (t * t) % 1000000007) % 1000000007 : (t * t) % 1000000007;
    }
};

int main()
{
    Solution solution;
    cout << solution.cuttingRope(2) << endl;
    cout << solution.cuttingRope(10) << endl;
    cout << solution.cuttingRope(8) << endl;
    cout << solution.cuttingRope(127) << endl;

    return 0;
}