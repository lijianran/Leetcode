
// 2021.06.07
// Leetcode 第 98 题
// https://leetcode-cn.com/problems/validate-binary-search-tree/

#include <iostream>
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

// 递归，中序遍历
// class Solution
// {
// private:
//     long long pre = (long long)INT64_MIN - 1;

// public:
//     bool isValidBST(TreeNode *root)
//     {
//         if (!root)
//             return true;

//         if (!isValidBST(root->left))
//             return false;

//         if (pre >= root->val)
//             return false;
//         pre = root->val;

//         return isValidBST(root->right);
//     }
// };

// 循环，中序遍历
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        std::stack<TreeNode *> stack;
        long long pre = (long long)INT64_MIN - 1;

        while (!stack.empty() || !root)
        {
            while (!root)
            {
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();
            
            if (root->val <= pre)
            {
                return false;
            }
            pre = root->val;
            root = root->right;
        }

        return true;
    }
};
