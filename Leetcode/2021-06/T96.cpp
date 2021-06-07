
// 2021.06.07
// Leetcode 第 96 题
// https://leetcode-cn.com/problems/unique-binary-search-trees/

#include <iostream>
#include <vector>

// DP
class Solution
{
public:
    int numTrees(int n)
    {
        std::vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};
