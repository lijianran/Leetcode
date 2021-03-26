
// 2021.03.26
// 剑指offer 第32题(2)
// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
#include <iostream>
#include <vector>
#include <stack>
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

        std::stack<TreeNode *> levels[2];
        int current = 0;
        int next = 1;

        std::vector<int> row;
        levels[current].push(root);
        while (!levels[0].empty() || !levels[1].empty())
        {
            TreeNode *pNode = levels[current].top();
            levels[current].pop();
            row.push_back(pNode->val);

            if (current == 0)
            {
                if (pNode->left)
                {
                    levels[next].push(pNode->left);
                }
                if (pNode->right)
                {
                    levels[next].push(pNode->right);
                }
            }
            else
            {
                if (pNode->right)
                {
                    levels[next].push(pNode->right);
                }
                if (pNode->left)
                {
                    levels[next].push(pNode->left);
                }
            }

            if (levels[current].empty())
            {
                result.push_back(row);
                row.clear();
                current = 1 - current;
                next = 1 - next;
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
