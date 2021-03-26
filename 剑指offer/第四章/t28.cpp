
// 2021.03.25
// 剑指offer 第28题
// https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
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
    bool isSymmetric(TreeNode *root)
    {
        return isSymmetrical(root, root);
    }

    bool isSymmetrical(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }

        if (root1 == nullptr || root2 == nullptr)
        {
            return false;
        }

        if (root1->val != root2->val)
        {
            return false;
        }

        return isSymmetrical(root1->left, root2->right) && isSymmetrical(root1->right, root2->left);
    }
};

int main()
{
    Solution solution;
    // TreeNode a(1);
    // TreeNode b(2);
    // TreeNode c(2);
    // TreeNode d(3);
    // TreeNode e(4);
    // TreeNode f(4);
    // TreeNode g(3);

    // a.left = &b;
    // a.right = &c;
    // b.left = &d;
    // b.right = &e;
    // c.left = &f;
    // c.right = &g;

    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(3);

    a.left = &b;
    a.right = &c;
    b.right = &d;
    c.right = &e;

    cout << solution.isSymmetric(&a) << endl;

    return 0;
}