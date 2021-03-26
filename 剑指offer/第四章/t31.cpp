
// 2021.03.26
// 剑指offer 第31题
// https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
#include <iostream>
#include <vector>
#include <stack>
using std::vector;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        bool bPossible = false;
        int length = pushed.size();

        if (length == 0 && popped.size() == 0)
        {
            return true;
        }

        if (length > 0)
        {
            int pushIndex = 0;
            int popIndex = 0;

            std::stack<int> stackData;

            while (popIndex < length)
            {
                while (stackData.empty() || stackData.top() != popped[popIndex])
                {
                    if (pushIndex == length)
                    {
                        break;
                    }

                    stackData.push(pushed[pushIndex]);
                    pushIndex++;
                }

                if (stackData.top() != popped[popIndex])
                {
                    break;
                }

                stackData.pop();
                popIndex++;
            }

            if (stackData.empty() && popIndex == length)
            {
                bPossible = true;
            }
        }

        return bPossible;
    }
};

int main()
{
    Solution solution;

    // vector<int> pushed = {1, 2, 3, 4, 5};
    // vector<int> popped = {4, 5, 3, 2, 1};

    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 3, 5, 1, 2};

    std::cout << solution.validateStackSequences(pushed, popped) << std::endl;

    return 0;
}