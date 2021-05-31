
// 2021.05.31
// Leetcode 第 3 题
// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <string>
using std::string;

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int hash[130];
//         int i = -1;
//         int result = 0;
//         for (int j = 0; j < s.size(); ++j)
//         {
//             if (hash[s[j]])
//             {
//                 i = (hash[s[j]] > i ? hash[s[j]] : i);
//             }
//             result = (result > (j - i) ? result : (j - i));
//             hash[s[j]] = j;
//         }
//         return result;
//     }
// };

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int hash[256] = {0};
        int left = 0;
        int right = -1;
        int result = 0;
        // 整个循环从 left == 0; right == -1 这个空窗口开始
        // 到 left == s.size(); right == s.size()-1 这个空窗口截止
        // 在每次循环里逐渐改变窗口, 维护 hash, 并记录当前窗口中是否找到了一个新的最优值
        while (left < s.size())
        {
            if (right + 1 < s.size() && hash[s[right + 1]] == 0)
            {
                // 新的字符没有出现过
                ++right;
                ++hash[s[right]];
            }
            else
            {
                // 滑动窗口右边没有字符了，或者新的字符原来出现过
                --hash[s[left]];
                ++left;
            }
            result = result > (right - left + 1) ? result : (right - left + 1);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::cout << solution.lengthOfLongestSubstring("abdd") << std::endl;

    return 0;
}