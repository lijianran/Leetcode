
// 2021.03.15
// 剑指offer 第14题(1)
// https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
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

        vector<int> products(n + 1);

        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;

        int max = 0;
        for (int i = 4; i <= n; i++)
        {
            max = 0;
            for (int j = 0; j <= i / 2; j++)
            {
                int product = products[j] * products[i - j];
                if (max < product)
                {
                    max = product;
                }
                products[i] = max;
            }
        }

        max = products[n];

        return max;
    }
};

int main()
{
    Solution solution;
    cout << solution.cuttingRope(2) << endl;
    cout << solution.cuttingRope(10) << endl;
    cout << solution.cuttingRope(8) << endl;
    cout << solution.cuttingRope(58) << endl;

    return 0;
}