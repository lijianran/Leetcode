
// 2021.05.30
// Leetcode 第 97 题
// https://leetcode-cn.com/problems/interleaving-string/

#include <iostream>
#include <string>
#include <vector>
using std::string;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 + n2 != s3.size())
        {
            return false;
        }

        // dp[i][j] 表示 s1[0~i-1] 和 s2[0~j-1] 是否能交错组成 s3[0~i+j-1]
        std::vector<std::vector<bool>> dp(n1 + 1, std::vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        for (size_t i = 1; i <= n1; ++i)
        {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        for (size_t i = 1; i <= n2; ++i)
        {
            dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
        }

        for (size_t i = 1; i <= n1; ++i)
        {
            for (size_t j = 1; j <= n2; ++j)
            {
                dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i - 1 + j]) ||
                           dp[i][j - 1] && (s2[j - 1] == s3[j - 1 + i]);
            }
        }

        return dp[n1][n2];
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}