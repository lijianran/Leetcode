
// 2021.03.22
// 剑指offer 第20题
// https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        if (s.empty())
        {
            return false;
        }
        int count = 0;

        while (s[count] == ' ')
        {
            ++count;
        }

        bool numeric = scanInteger(s, &count);

        if (s[count] == '.')
        {
            ++count;
            if (s[count] == ' ' && count <= 1)
            {
                return false;
            }

            numeric = scanUnsignedInteger(s, &count) || numeric;
        }

        if (s[count] == 'e' || s[count] == 'E')
        {
            ++count;

            numeric = numeric && scanInteger(s, &count);
        }

        return numeric && count == s.size();
    }

    bool scanInteger(string s, int *count)
    {
        if (s[*count] == '+' || s[*count] == '-')
        {
            ++(*count);
        }

        return scanUnsignedInteger(s, count);
    }

    bool scanUnsignedInteger(string s, int *count)
    {
        const int before = *count;

        while (s.size() != *count && s[*count] >= '0' && s[*count] <= '9')
        {
            ++(*count);
        }
        while (*count < s.size() && s[*count] == ' ' && *count != 0)
        {
            ++(*count);
        }

        return *count > before;
    }
};

int main()
{
    Solution solution;

    // cout << solution.isNumber("+100") << endl;
    // cout << solution.isNumber("5e2") << endl;
    // cout << solution.isNumber("-123") << endl;
    // cout << solution.isNumber("3.1416") << endl;
    // cout << solution.isNumber("-1E-16") << endl;

    // cout << solution.isNumber("12E") << endl;
    // cout << solution.isNumber("1a3.14") << endl;
    // cout << solution.isNumber("1.2.3") << endl;
    // cout << solution.isNumber("+-5") << endl;
    // cout << solution.isNumber("12e+5.4") << endl;

    // cout << solution.isNumber("1 ") << endl;
    // cout << solution.isNumber(" ") << endl;
    // cout << solution.isNumber(" 0") << endl;
    cout << solution.isNumber(". ") << endl;
    // cout << solution.isNumber("1  ") << endl;
    cout << solution.isNumber("3. ") << endl;

    return 0;
}