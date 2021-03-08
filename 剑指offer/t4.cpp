
// 2021.03.08
// 剑指offer 第4题
// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
        {
            return false;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();

        if (row <= 0 || col <= 0)
        {
            return false;
        }

        int index_row = 0;
        int index_col = col - 1;
        while (index_row < row && index_col >= 0)
        {
            if (matrix[index_row][index_col] == target)
            {
                return true;
            }
            else if (matrix[index_row][index_col] > target)
            {
                --index_col;
            }
            else
            {
                ++index_row;
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> matrix(5, vector<int>(5, 0));

    matrix[0] = {1,   4,  7, 11, 15};
    matrix[1] = {2,   5,  8, 12, 19};
    matrix[2] = {3,   6,  9, 16, 22};
    matrix[3] = {10, 13, 14, 17, 24};
    matrix[4] = {18, 21, 23, 26, 30};


    vector<vector<int>> matrix1;

    cout << ((solution.findNumberIn2DArray(matrix, 20)==true)?"true":"false") << endl;
}