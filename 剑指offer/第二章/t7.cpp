
// 2021.03.10
// 剑指offer 第7题
// https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
#include <iostream>
#include <vector>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(preorder, inorder, 0, 0, inorder.size() - 1);

        // int rootValue = preorder[0];
        // TreeNode *root = new TreeNode(rootValue);

        // if (preorder.size() == 1)
        // {
        //     if (inorder.size() == 1 && preorder[0] == inorder[0])
        //     {
        //         return root;
        //     }
        //     else
        //     {
        //         cout << "错误的输入" << endl;
        //         return;
        //     }
        // }

        // int rootInorder = 0;
        // while (rootInorder < inorder.size() && inorder[rootInorder] != rootValue)
        // {
        //     ++rootInorder;
        // }

        // if (rootInorder == inorder.size() - 1 && inorder[rootInorder] != rootValue)
        // {
        //     cout << "错误的输入" << endl;
        //     return;
        // }

        // root->left=buildTree()
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int root, int start, int end)
    {
        if (start > end)
            return NULL;
        
        TreeNode *tree = new TreeNode(preorder[root]);
        int i = start;
        while (i < end && preorder[root] != inorder[i])
            i++;

        tree->left = build(preorder, inorder, root + 1, start, i - 1);
        tree->right = build(preorder, inorder, root + 1 + i - start, i + 1, end);

        return tree;
    }
};

int main()
{
    Solution solution;

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *tree = solution.buildTree(preorder, inorder);

    return 0;
}