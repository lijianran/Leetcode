
// 2021.04.09
// 剑指offer 第54题
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
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
    int kthLargest(TreeNode *root, int k)
    {
        if (!root || k == 0)
        {
            return -1;
        }

        return KthNodeCore(root, k)->val;
    }

    TreeNode *KthNodeCore(TreeNode *root, int &k)
    {
        TreeNode *target = nullptr;

        if (root->right)
        {
            target = KthNodeCore(root->right, k);
        }

        if (target == nullptr)
        {
            if (k == 1)
            {
                target = root;
            }
            k--;
        }

        if (target == nullptr && root->left)
        {
            target = KthNodeCore(root->left, k);
        }

        return target;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode a(3);
    TreeNode b(1);
    TreeNode c(4);
    TreeNode d(2);
    a.left = &b;
    a.right = &c;
    b.right = &d;

    std::cout << solution.kthLargest(&a, 1) << std::endl;

    return 0;
}
