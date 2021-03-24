
// 2021.03.09
// 剑指offer 第5题
// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        // 原始长度
        int length = s.length();
        if (length <= 0 || length > 10000)
        {
            return s;
        }

        // 空格个数
        int numberOfBlank = 0;
        for (size_t i = 0; i < length; i++)
        {
            if (s[i] == ' ')
            {
                ++numberOfBlank;
            }
        }

        
        int newLength = length + numberOfBlank * 2;
        s.resize(newLength, 'a');

        int indexOfOriginal = length - 1;
        int indexOfNew = newLength - 1;

        while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
        {
            if (s[indexOfOriginal] == ' ')
            {
                s[indexOfNew--] = '0';
                s[indexOfNew--] = '2';
                s[indexOfNew--] = '%';
            }
            else
            {
                s[indexOfNew--] = s[indexOfOriginal];
            }

            --indexOfOriginal;
        }

        return s;
    }
};

int main()
{
    string test;
    string test1 = " ";
    string test2 = "1  %2 0";
    char test3[] = " ";

    string s = "Wearehappy.";

    Solution solution;

    cout << '"' << solution.replaceSpace(s) << '"' << endl;

    return 0;
}