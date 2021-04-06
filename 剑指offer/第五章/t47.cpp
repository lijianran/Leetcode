
// 2021.04.06
// 剑指offer 第47题
// https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> maxValues(cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int left = 0;
                int up = 0;

                if (i > 0)
                {
                    up = maxValues[j];
                }
                if (j > 0)
                {
                    left = maxValues[j - 1];
                }

                maxValues[j] = (std::max(left, up)) + grid[i][j];
            }
        }

        int maxValue = maxValues[cols - 1];

        return maxValue;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> test1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> test2 = {{1, 10, 3, 8}, {12, 2, 9, 6}, {5, 7, 4, 11}, {3, 7, 16, 5}};

    std::cout << solution.maxValue(test2) << std::endl;
    return 0;
}
