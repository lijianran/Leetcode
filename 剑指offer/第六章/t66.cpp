
// 2021.04.12
// 剑指offer 第66题
// https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> constructArr(vector<int> &a)
    {
        int length = a.size();

        if (length > 1)
        {
            vector<int> result(a.size(), 0);

            result[0] = 1;
            for (int i = 1; i < length; i++)
            {
                result[i] = result[i - 1] * a[i - 1];
            }

            double temp = 1;
            for (int i = length - 2; i >= 0; --i)
            {
                temp *= a[i + 1];
                result[i] *= temp;
            }

            return result;
        }

        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test1 = {1, 2, 3, 4, 5};
    vector<int> test2;

    vector<int> result = solution.constructArr(test1);

    return 0;
}
