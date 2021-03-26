
// 2021.03.25
// 剑指offer 第29题
// https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
        {
            return {};
        }

        int rows = matrix.size();
        int columns = matrix[0].size();

        int start = 0;
        vector<int> result;
        while (columns > start * 2 && rows > start * 2)
        {
            // printMatrixInCircle(matrix, columns, rows, start);
            int endX = columns - 1 - start;
            int endY = rows - 1 - start;

            // 从左到右打印一行
            for (int i = start; i <= endX; i++)
            {
                result.push_back(matrix[start][i]);
            }

            // 从上到下打印一列
            if (start < endY)
            {
                for (int i = start + 1; i <= endY; i++)
                {
                    result.push_back(matrix[i][endX]);
                }
            }

            // 从右到左打印一行
            if (start < endX && start < endY)
            {
                for (int i = endX - 1; i >= start; --i)
                {
                    result.push_back(matrix[endY][i]);
                }
            }

            // 从下到上打印一列
            if (start < endX && start < endY - 1)
            {
                for (int i = endY - 1; i >= start + 1; --i)
                {
                    result.push_back(matrix[i][start]);
                }
            }

            ++start;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> test1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> test2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    vector<vector<int>> test3 = {{7}, {9}, {6}};

    vector<int> result = solution.spiralOrder(test3);

    return 0;
}
