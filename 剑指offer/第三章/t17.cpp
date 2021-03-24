
// 2021.03.18
// 剑指offer 第17题
// https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> printNumbers(int n)
    {
        if (n <= 0)
        {
            return {};
        }

        string number(n, '0');

        for (int i = 0; i < 10; i++)
        {
            number[0] = i + '0';
            Print1ToMaxOfNDigitsRecursively(number, n, 0);
        }

        return result;
    }

    void Print1ToMaxOfNDigitsRecursively(string &number, int length, int index)
    {
        if (index == length - 1)
        {
            SaveNumber(number);
            return;
        }

        for (int i = 0; i < 10; i++)
        {
            number[index + 1] = i + '0';
            Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
        }
    }

    void SaveNumber(string &number)
    {
        bool isBegining0 = true;
        int nLength = number.size();
        int temp = 0;
        for (int i = 0; i < nLength; i++)
        {
            if (isBegining0 && number[i] != '0')
            {
                isBegining0 = false;
            }

            if (!isBegining0)
            {
                temp = temp * 10 + number[i] - '0';
            }
        }
        if (temp != 0)
        {
            result.push_back(temp);
        }
    }

private:
    vector<int> result;
};

int main()
{
    Solution solution;

    vector<int> result = solution.printNumbers(-1);
    return 0;
}