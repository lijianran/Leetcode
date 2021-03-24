
// 2021.03.24
// 剑指offer 第26题
// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
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
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        bool result = false;

        if (A != nullptr && B != nullptr)
        {
            if (A->val == B->val)
            {
                result = DoesAHaveB(A, B);
            }

            if (!result)
            {
                result = isSubStructure(A->left, B);
            }
            if (!result)
            {
                result = isSubStructure(A->right, B);
            }  
        }

        return result;
    }

    bool DoesAHaveB(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr)
        {
            return true;
        }

        if (A == nullptr)
        {
            return false;
        }

        if (A->val != B->val)
        {
            return false;
        }

        return DoesAHaveB(A->left, B->left) && DoesAHaveB(A->right, B->right);
    }
};

int main()
{
    Solution solution;
    // TreeNode a(1);
    // TreeNode b(2);
    // TreeNode c(3);
    // a.left = &b;
    // a.right = &c;

    // TreeNode d(3);
    // TreeNode e(1);
    // d.left = &e;

    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);

    a.left = &b;
    a.right = &c;
    b.left = &d;

    TreeNode e(3);

    cout << solution.isSubStructure(&a, &e) << endl;

    return 0;
}