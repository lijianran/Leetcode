
// 2021.06.04
// Leetcode 第 48 题
// https://leetcode-cn.com/problems/rotate-image/

#include <iostream>
#include <vector>
using std::vector;

// 先上下反转，再对角反转
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // 先上下反转
        for (int i = 0; i < (n >> 1); ++i)
        {
            std::swap(matrix[i], matrix[n - 1 - i]);
        }

        // 再对角反转
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};