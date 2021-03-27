

// 2021.03.27
// 剑指offer 第34题
// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
#include <iostream>
#include <vector>
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

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        if (!root)
        {
            return {};
        }
        std::vector<int> path;
        std::vector<std::vector<int>> result;
        int currentSum = 0;
        findPath(root, target, currentSum, path, result);

        return result;
    }

    void findPath(TreeNode *root, int expectedSum, int currentSum, std::vector<int> &path, std::vector<std::vector<int>> &result)
    {
        currentSum += root->val;
        path.push_back(root->val);

        bool isLeaf = !(root->left || root->right);

        if (expectedSum == currentSum && isLeaf)
        {
            result.push_back(path);
        }

        if (root->left)
        {
            findPath(root->left, expectedSum, currentSum, path, result);
        }
        if (root->right)
        {
            findPath(root->right, expectedSum, currentSum, path, result);
        }

        path.pop_back();
    }
};

int main()
{
    Solution solution;

    TreeNode a(7);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(1);

    TreeNode e(11, &a, &b);
    TreeNode f(4, &c, &d);

    TreeNode g(13);

    TreeNode h(8, &g, &f);
    TreeNode i(4, &e, nullptr);

    TreeNode root(5, &i, &h);

    std::vector<std::vector<int>> result = solution.pathSum(&root, 22);
    
    return 0;
}