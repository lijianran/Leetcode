
// 2021.05.30
// Leetcode 第 5 题
// https://leetcode-cn.com/problems/longest-palindromic-substring/

#include <iostream>
#include <string>
#include <vector>
using std::string;

// DP
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
        {
            return "";
        }
        int length = s.length();
        std::string result;
        int len = 1;
        // dp[i][j] 表示从下标 i 到下标 j 的字符串是回文
        std::vector<std::vector<bool>> dp(length, std::vector<bool>(length, false));

        for (int i = length - 1; i >= 0; --i)
        {
            for (int j = i; j < length; ++j)
            {
                if (i == j)
                {
                    // 只有一个字符，是回文
                    dp[i][j] = true;
                }
                else if (j == i + 1)
                {
                    // 两个字符，判断是否相等
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    // 三个字符及以上，判断头尾是否相等，同时判断去掉头尾的字符串是否是回文
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }

                if (dp[i][j])
                {
                    // 长度大于最大回文串的长度
                    if (j - i + 1 >= len)
                    {
                        // 更新长度和结果
                        len = j - i + 1;
                        result = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return result;
    }
};

// 中心扩散法
// class Solution
// {
// public:
//     std::pair<int, int> expandAroundCenter(const string &s, int left, int right)
//     {
//         while (left >= 0 && right < s.size() && s[left] == s[right])
//         {
//             --left;
//             ++right;
//         }
//         return {left + 1, right - 1};
//     }

//     string longestPalindrome(string s)
//     {
//         int start = 0, end = 0;
//         for (int i = 0; i < s.size(); ++i)
//         {
//             auto [left1, right1] = expandAroundCenter(s, i, i);
//             auto [left2, right2] = expandAroundCenter(s, i, i + 1);
//             if (right1 - left1 > end - start)
//             {
//                 start = left1;
//                 end = right1;
//             }
//             if (right2 - left2 > end - start)
//             {
//                 start = left2;
//                 end = right2;
//             }
//         }
//         return s.substr(start, end - start + 1);
//     }
// };

int main(int argc, char const *argv[])
{
    Solution solution;
    std::cout << solution.longestPalindrome("aba") << std::endl;
    return 0;
}