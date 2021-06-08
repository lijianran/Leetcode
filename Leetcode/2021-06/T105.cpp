
// 2021.06.08
// Leetcode 第 105 题
// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <iostream>
#include <vector>
#include <unordered_map>
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归
class Solution
{
private:
    std::unordered_map<int, int> index;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() != inorder.size())
            return nullptr;

        int n = inorder.size();
        for (int i = 0; i < n; ++i)
        {
            index[inorder[i]] = i;
        }

        return makeTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *makeTree(const std::vector<int> &preorder, const std::vector<int> &inorder,
                       int pleft, int pright, int ileft, int iright)
    {
        if (pleft > pright)
        {
            return nullptr;
        }
        // 父节点
        TreeNode *root = new TreeNode(preorder[pleft]);
        // preorder[pleft] 前序遍历的第一个元素是父节点，找到这个节点在中序遍历中的下标
        int root_index = index[preorder[pleft]];
        // 左子树的个数
        int size_left = root_index - ileft;
        // 递归构造左右子树
        root->left = makeTree(preorder, inorder, pleft + 1, pleft + size_left, ileft, root_index - 1);
        root->right = makeTree(preorder, inorder, pleft + size_left + 1, pright, root_index + 1, iright);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}
