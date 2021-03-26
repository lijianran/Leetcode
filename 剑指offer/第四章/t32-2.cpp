
// 2021.03.26
// 剑指offer 第32题(2)
// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
        {
            return result;
        }

        std::queue<TreeNode *> nodes;
        nodes.push(root);
        int nextLevel = 0;
        int toBePrint = 1;
        vector<int> row;
        while (!nodes.empty())
        {
            TreeNode *pNode = nodes.front();
            row.push_back(pNode->val);

            if (pNode->left)
            {
                nodes.push(pNode->left);
                ++nextLevel;
            }

            if (pNode->right)
            {
                nodes.push(pNode->right);
                ++nextLevel;
            }

            nodes.pop();
            --toBePrint;
            if (toBePrint == 0)
            {
                result.push_back(row);
                row.clear();
                toBePrint = nextLevel;
                nextLevel = 0;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;

    TreeNode a(3);
    TreeNode b(9);
    TreeNode c(20);
    TreeNode d(15);
    TreeNode e(7);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;

    vector<vector<int>> result = solution.levelOrder(&a);
    
    return 0;
}