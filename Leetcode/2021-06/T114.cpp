
// 2021.06.10
// Leetcode 第 114 题
// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 原地算法 寻找前驱节点
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        TreeNode *current = root;
        while (current)
        {
            if (current->left)
            {
                TreeNode *next = current->left;
                TreeNode *pre = next;
                while (pre->right)
                {
                    pre = pre->right;
                }
                pre->right = current->right;
                current->left = nullptr;
                current->right = next;
            }
            current = current->right;
        }
    }
};

// 前序遍历 递归
class Solution1
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        std::vector<TreeNode *> list;
        preOrder(root, list);
        for (int i = 1; i < list.size(); ++i)
        {
            TreeNode *pre = list.at(i - 1);
            TreeNode *cur = list.at(i);
            pre->left = nullptr;
            pre->right = cur;
        }
    }

private:
    void preOrder(TreeNode *root, std::vector<TreeNode *> &list)
    {
        if (root)
        {
            list.push_back(root);
            preOrder(root->left, list);
            preOrder(root->right, list);
        }
    }
};

// 前序遍历 迭代
class Solution2
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        std::vector<TreeNode *> list;
        std::stack<TreeNode *> stack;
        TreeNode *node = root;
        while (node || !stack.empty())
        {
            while (node)
            {
                // 访问 当前根
                list.push_back(node);
                stack.push(node);
                // 访问 左子树
                node = node->left;
            }
            // 访问完左子树
            node = stack.top();
            stack.pop();
            // 访问 右子树
            node = node->right;
        }

        for (int i = 1; i < list.size(); ++i)
        {
            TreeNode *pre = list.at(i - 1);
            TreeNode *cur = list.at(i);
            pre->left = nullptr;
            pre->right = cur;
        }
    }
};

// 前序遍历
class Solution3
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        std::stack<TreeNode *> stack;
        TreeNode *pre = nullptr;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *cur = stack.top();
            stack.pop();
            // 拼接到右子树
            if (pre)
            {
                pre->left = nullptr;
                pre->right = cur;
            }
            TreeNode *left = cur->left;
            TreeNode *right = cur->right;
            if (right)
                stack.push(right);
            if (left)
                stack.push(left);
            
            pre = cur;
        }
    }
};