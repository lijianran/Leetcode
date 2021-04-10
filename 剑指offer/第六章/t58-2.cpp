
// 2021.04.10
// 剑指offer 第58题(2)
// https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
#include <iostream>
#include <string>
using std::string;

class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        int length = s.size();
        if (length > 0 && n > 0 && n < length)
        {
            reverse(s, 0, n - 1);
            reverse(s, n, length - 1);
            reverse(s, 0, length - 1);
        }
        return s;
    }

    void reverse(string &s, int begin, int end)
    {
        while (begin < end)
        {
            char temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;

            begin++;
            end--;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::cout << solution.reverseLeftWords("abcdefg", 2) << std::endl;
    std::cout << solution.reverseLeftWords("lrloseumgh", 6) << std::endl;

    return 0;
}
