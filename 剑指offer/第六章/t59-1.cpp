
// 2021.04.10
// 剑指offer 第59题(1)
// https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
#include <iostream>
#include <vector>
#include <deque>
using std::vector;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> maxInWindows;
        if (nums.size() >= k && k >= 1)
        {
            std::deque<int> index;

            for (unsigned int i = 0; i < k; i++)
            {
                while (!index.empty() && nums[i] > nums[index.back()])
                {
                    index.pop_back();
                }

                index.push_back(i);
            }

            for (int i = k; i < nums.size(); i++)
            {
                maxInWindows.push_back(nums[index.front()]);

                while (!index.empty() && nums[i] >= nums[index.back()])
                {
                    index.pop_back();
                }
                if (!index.empty() && index.front() <= (int)(i - k))
                {
                    index.pop_front();
                }

                index.push_back(i);
            }

            maxInWindows.push_back(nums[index.front()]);
        }

        return maxInWindows;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test1 = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> test2 = {1};

    vector<int> result = solution.maxSlidingWindow(test2, 1);

    return 0;
}
