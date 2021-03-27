
// 2021.03.27
// 剑指offer 第33题
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    bool verifyPostorder(vector<int> &postorder)
    {
        int length = postorder.size();
        if (length < 0)
        {
            return false;
        }

        return VerifySquenceOfBST(postorder, 0, length - 1);
    }

    bool VerifySquenceOfBST(vector<int> &postorder, int left, int right)
    {
        if (left >= right)
            return true;

        int root = postorder[right];

        int i = left;
        for (; i < right; i++)
        {
            if (postorder[i] > root)
            {
                break;
            }
        }

        int j = i;
        for (; j < right; j++)
        {
            if (postorder[j] < root)
            {
                return false;
            }
        }

        bool flag_left = true;
        if (i > 0)
        {
            flag_left = VerifySquenceOfBST(postorder, left, i - 1);
        }

        bool flag_right = true;
        if (i < right)
        {
            flag_right = VerifySquenceOfBST(postorder, i, right - 1);
        }

        return (flag_left && flag_right);
    }
};

int main()
{
    Solution solution;

    vector<int> test1 = {1, 6, 3, 2, 5};
    vector<int> test2 = {1, 3, 2, 6, 5};
    vector<int> test3;

    std::cout << solution.verifyPostorder(test1) << std::endl;
    std::cout << solution.verifyPostorder(test2) << std::endl;
    std::cout << solution.verifyPostorder(test3) << std::endl;


    return 0;
}