
// 2021.04.09
// 剑指offer 第55题(1)
// https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
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
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return (left > right) ? (left + 1) : (right + 1);
    }
};