
// 2021.03.15
// 剑指offer 第13题
// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        if (m <= 0 || n <= 0 || k < 0)
        {
            return 0;
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = movingCountCore(m, n, k, 0, 0, visited);

        return count;
    }

    int movingCountCore(int rows, int cols, int k, int row, int col, vector<vector<bool>> &visited)
    {
        int count = 0;
        if (check(k, rows, cols, row, col, visited))
        {
            visited[row][col] = true;
            count = 1 + movingCountCore(rows, cols, k, row - 1, col, visited) + movingCountCore(rows, cols, k, row, col - 1, visited) + movingCountCore(rows, cols, k, row + 1, col, visited) + movingCountCore(rows, cols, k, row, col + 1, visited);
        }
        return count;
    }

    bool check(int k, int rows, int cols, int row, int col, const vector<vector<bool>> &visited)
    {
        if (row >= 0 && col >= 0 && row < rows && col < cols && getDigitSum(row) + getDigitSum(col) <= k && !visited[row][col])
        {
            return true;
        }

        return false;
    }

    int getDigitSum(int number)
    {
        int sum = 0;
        while (number > 0)
        {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    cout << solution.movingCount(2, 3, 1) << endl;
    cout << solution.movingCount(3, 1, 0) << endl;
    cout << solution.movingCount(1, 4, 3) << endl;
    cout << solution.movingCount(2, 3, -1) << endl;



    return 0;
}