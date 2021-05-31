
// 2021.05.31
// Leetcode 第 6 题
// https://leetcode-cn.com/problems/zigzag-conversion/

#include <iostream>
#include <string>
#include <vector>
using std::string;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        std::vector<std::string> rows(std::min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
            {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        string result;
        for (string row : rows)
        {
            result += row;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::cout << solution.convert("PAYPALISHIRING", 3) << std::endl;
    return 0;
}
