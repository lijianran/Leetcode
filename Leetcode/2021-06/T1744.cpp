
// 2021.06.01
// Leetcode 第 1744 题
// https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/

#include <iostream>
#include <vector>
using std::vector;

class Solution
{
private:
    using LL = long long;

public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
    {
        int n = candiesCount.size();

        std::vector<LL> sum(n);
        sum[0] = candiesCount[0];
        // 前缀和
        for (size_t i = 1; i < n; ++i)
        {
            sum[i] = sum[i - 1] + candiesCount[i];
        }

        vector<bool> answer;
        for (const auto &query : queries)
        {
            int favoriteType = query[0];
            int favoriteDay = query[1];
            int dailyCap = query[2];

            LL x1 = favoriteDay + 1;
            LL y1 = (LL)(favoriteDay + 1) * dailyCap;

            LL x2 = (favoriteType == 0 ? 1 : (sum[favoriteType - 1] + 1));
            LL y2 = sum[favoriteType];

            answer.push_back(!(x1 > y2 || y1 < x2));
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
