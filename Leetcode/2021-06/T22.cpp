
// 2021.06.03
// Leetcode 第 22 题
// https://leetcode-cn.com/problems/generate-parentheses/

#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        std::vector<std::string> result;
        std::string temp;
        backtrace(result, temp, 0, 0, n);
        return result;
    }

private:
    void backtrace(std::vector<std::string> &result, std::string &temp, int open, int close, const int &n)
    {
        if (close > open)
        {
            return;
        }
        if (temp.size() == 2 * n)
        {
            result.push_back(temp);
            return;
        }

        if (open < n)
        {
            temp.push_back('(');
            backtrace(result, temp, open + 1, close, n);
            temp.pop_back();
        }
        if (close < n)
        {
            temp.push_back(')');
            backtrace(result, temp, open, close + 1, n);
            temp.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    auto result = solution.generateParenthesis(3);
    return 0;
}