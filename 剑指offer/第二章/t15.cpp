
// 2021.03.15
// 剑指offer 第15题
// https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;

        while (n)
        {
            n &= n - 1;
            count++;
        }
        return count;
    }
};

int main()
{
    Solution solution;

    cout << solution.hammingWeight(00000000000000000000000000001011) << endl;
    cout << solution.hammingWeight(00000000000000000000000010000000) << endl;
    cout << solution.hammingWeight(11111111111111111111111111111101) << endl;
    
    return 0;
}