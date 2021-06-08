
// 2021.06.08
// Leetcode 第 114 题
// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        
        flatten(root->left);

        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        root->right->right = temp;

        // flatten(root->right);
    }
};
