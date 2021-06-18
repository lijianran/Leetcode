
// 2021.06.18
// Leetcode 第 221 题
// https://leetcode-cn.com/problems/maximal-square/

#include <iostream>
#include <vector>
using std::vector;

// 暴力法 O(mn * min(m,n)^2)
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    maxSide = std::max(maxSide, 1);
                    int currentMaxSide = std::min(rows - i, cols - j);
                    for (int k = 1; k < currentMaxSide; ++k)
                    {
                        if (matrix[i + k][j + k] == '0')
                        {
                            break;
                        }

                        bool flag = true;
                        for (int m = 0; m < k; ++m)
                        {
                            if (matrix[i + k][j + m] == '0' || matrix[i + m][j + k] == '0')
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                        {
                            maxSide = std::max(k + 1, maxSide);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        return maxSide * maxSide;
    }
};

// DP O(m*n)
// dp(i,j) = min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1)) + 1
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    }
                    maxSide = std::max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
};
