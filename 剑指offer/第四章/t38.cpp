
// 2021.03.28
// 剑指offer 第38题
// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

class Solution
{
public:
    vector<string> permutation(string s)
    {
        vector<string> result;

        if (s.size() == 0)
        {
            return result;
        }
        Permutation(result, s, 0);

        return result;
    }

    void Permutation(vector<string> &result, string &s, int begin)
    {
        if (begin == s.size())
        {
            result.push_back(s);
        }
        else
        {
            for (size_t i = begin; i < s.size(); i++)
            {
                bool flag = true;
                for (int j = begin; j < i; j++) //字母相同时，等效，剪枝
                    if (s[j] == s[i])
                        flag = false;

                if (flag)
                {
                    std::swap(s[begin], s[i]);
                    Permutation(result, s, begin + 1);
                    std::swap(s[begin], s[i]);
                }
            }
        }
    }
};

int main()
{
    Solution solution;
    string str = "aab";

    vector<string> result = solution.permutation(str);

    return 0;
}
