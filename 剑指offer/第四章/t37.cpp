
// 2021.03.28
// 剑指offer 第37题
// https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
#include <iostream>
#include <string>
using std::string;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
private:
    string m_str;

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
        {
            m_str += "null,";
            return m_str;
        }

        m_str += std::to_string(root->val) + ",";
        serialize(root->left);
        serialize(root->right);

        return m_str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    Codec codec;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);

    a.left = &b;
    a.right = &c;

    string result = codec.serialize(&a);

    return 0;
}