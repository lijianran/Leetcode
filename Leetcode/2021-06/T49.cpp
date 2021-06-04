
// 2021.06.04
// Leetcode 第 49 题
// https://leetcode-cn.com/problems/group-anagrams/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using std::string;
using std::vector;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        std::map<std::string, std::vector<std::string>> map;
        for (auto &str : strs)
        {
            std::string temp = str;
            // std::sort(str.begin(), str.end());
            std::sort(temp.begin(), temp.end());

            map[temp].push_back(str);
        }

        std::vector<std::vector<std::string>> ret;
        for (const auto &m : map)
        {
            ret.push_back(m.second);
        }
        // for (const auto& [k, v] : map)
        // {
        //     ret.push_back(k);
        // }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ret = solution.groupAnagrams(strs);
    return 0;
}