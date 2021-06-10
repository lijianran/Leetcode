
// 2021.06.10
// Leetcode 第 139 题
// https://leetcode-cn.com/problems/word-break/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using std::string;
using std::vector;

// 动态规划
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int length = s.size();
        if (length <= 0)
            return false;
        std::vector<bool> dp(length + 1, false);
        dp[0] = true;

        std::unordered_set<std::string> set;
        for (auto &word : wordDict)
        {
            set.insert(word);
        }

        for (int i = 1; i <= length; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && set.find(s.substr(j, i - j)) != set.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[length];
    }
};
