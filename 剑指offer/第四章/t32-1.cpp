
// 2021.03.26
// 剑指offer 第32题(1)
// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
#include <iostream>
#include <vector>
#include <queue>
using std::vector;

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
    vector<int> levelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }

        std::vector<int> result;

        std::queue<TreeNode *> queueTreeNode;

        queueTreeNode.push(root);

        while (queueTreeNode.size())
        {
            TreeNode *pNode = queueTreeNode.front();
            queueTreeNode.pop();
            result.push_back(pNode->val);

            if (pNode->left)
            {
                queueTreeNode.push(pNode->left);
            }
            if (pNode->right)
            {
                queueTreeNode.push(pNode->right);
            }
        }

        return result;
    }
};

