
// 2021.06.08
// Leetcode 第 102 题
// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

#include <iostream>
#include <vector>
#include <queue>
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

// 自定义层次结构体
// class Solution
// {
// private:
//     struct node
//     {
//         TreeNode *treenode;
//         int level;
//     };

// public:
//     vector<vector<int>> levelOrder(TreeNode *root)
//     {
//         if (!root)
//             return {};

//         std::queue<node> queue;
//         queue.push({root, 0});
//         std::vector<std::vector<int>> ret(1, std::vector<int>{});
//         while (!queue.empty())
//         {
//             node node = queue.front();
//             queue.pop();
//             if (node.level > ret.size() - 1)
//                 ret.push_back({});
//             ret[node.level].push_back(node.treenode->val);
//             if (node.treenode->left)
//                 queue.push({node.treenode->left, node.level + 1});
//             if (node.treenode->right)
//                 queue.push({node.treenode->right, node.level + 1});
//         }
//         return ret;
//     }
// };

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        std::queue<TreeNode *> queue;
        queue.push(root);
        std::vector<std::vector<int>> ret;
        while (!queue.empty())
        {
            int currentLevelSize = queue.size();

            ret.push_back({});
            for (int i = 1; i <= currentLevelSize; ++i)
            {
                TreeNode *node = queue.front();
                queue.pop();
                ret.back().push_back(node->val);

                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::vector<std::vector<int>> ret;
    std::cout << ret.size() << std::endl;
    return 0;
}
