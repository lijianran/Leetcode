
// 2021.04.06
// 剑指offer 第48题
// https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {   
        int curLength = 0;
        int maxLength = 0;

        vector<int> position(26, -1);

        for (int i = 0; i < s.size(); i++)
        {
            int prevIndex = position[s[i] - 'a'];

            if (prevIndex < 0 || i - prevIndex > curLength)
            {
                ++curLength;
            }
            else
            {
                if (curLength > maxLength)
                {
                    maxLength = curLength;
                }

                curLength = i - prevIndex;
            }

            position[s[i] - 'a'] = i;
        }

        if (curLength > maxLength)
        {
            maxLength = curLength;
        }

        return maxLength;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    // std::cout << solution.lengthOfLongestSubstring("abcabcbb") << std::endl;
    // std::cout << solution.lengthOfLongestSubstring("bbbbb") << std::endl;
    // std::cout << solution.lengthOfLongestSubstring("pwwkew") << std::endl;
    std::cout << solution.lengthOfLongestSubstring(" ") << std::endl;

    return 0;
}
