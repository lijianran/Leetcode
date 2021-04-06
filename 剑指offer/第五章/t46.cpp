
// 2021.04.06
// 剑指offer 第46题
// https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    int translateNum(int num)
    {
        if (num < 0)
        {
            return 0;
        }

        std::string numInString = std::to_string(num);

        return getTranslateNum(numInString);
    }

    int getTranslateNum(const std::string &number)
    {
        int length = number.size();
        std::vector<int> counts(length);
        int count = 0;

        for (int i = length - 1; i >= 0; --i)
        {
            count = 0;
            if (i < length - 1)
            {
                count = counts[i + 1];
            }
            else
            {
                count = 1;
            }

            if (i < length - 1)
            {
                int digit1 = number[i] - '0';
                int digit2 = number[i + 1] - '0';
                int converted = digit1 * 10 + digit2;
                if (converted >= 10 && converted <= 25)
                {
                    if (i < length - 2)
                    {
                        count += counts[i + 2];
                    }
                    else
                    {
                        count += 1;
                    }
                }
            }

            counts[i] = count;
        }

        count = counts[0];
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::cout << solution.translateNum(12258) << std::endl;
    return 0;
}
