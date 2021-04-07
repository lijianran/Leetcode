
// 2021.04.07
// 剑指offer 第50题
// https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution
{
public:
    char firstUniqChar(string s)
    {
        vector<int> hastTable(256);

        for (int i = 0; i < s.size(); i++)
        {
            hastTable[s.at(i)]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (hastTable[s.at(i)] == 1)
            {
                return s.at(i);
            }
        }

        return ' ';
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    std::cout << "\"" << solution.firstUniqChar("abaccdeff") << "\"" << std::endl;

    return 0;
}
