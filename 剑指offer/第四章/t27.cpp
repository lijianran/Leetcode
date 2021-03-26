
// 2021.03.25
// 剑指offer 第27题
// https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
#include <iostream>
using namespace std;

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
    TreeNode *mirrorTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        // if (root->left == nullptr && root->right == nullptr)
        // {
        //     return nullptr;
        // }

        TreeNode *pTemp = root->left;
        root->left = root->right;
        root->right = pTemp;

        if (root->left)
        {
            mirrorTree(root->left);
        }

        if (root->right)
        {
            mirrorTree(root->right);
        }

        return root;
    }
};

int main()
{
    Solution solution;
    TreeNode a(4);
    TreeNode b(2);
    TreeNode c(7);
    TreeNode d(1);
    TreeNode e(3);
    TreeNode f(6);
    TreeNode g(9);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    TreeNode *result = solution.mirrorTree(&a);

    return 0;
}