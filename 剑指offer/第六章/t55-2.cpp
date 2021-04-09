
// 2021.04.09
// 剑指offer 第55题(2)
// https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        int depth = 0;
        return isBalanced(root, &depth);
    }

    bool isBalanced(TreeNode *root, int *depth)
    {
        if (!root)
        {
            *depth = 0;
            return true;
        }

        int left;
        int right;
        if (isBalanced(root->left, &left) && isBalanced(root->right, &right))
        {
            int diff = left - right;
            if (diff <= 1 && diff >= -1)
            {
                *depth = (left > right ? left : right) + 1;
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode a(3);
    TreeNode b(9);
    TreeNode c(20);
    TreeNode d(16);
    TreeNode e(7);

    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;

    std::cout << solution.isBalanced(&a) << std::endl;

    return 0;
}
