
// 2021.03.28
// 剑指offer 第36题
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
#include <iostream>

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        Node *pLastNodeInList = nullptr;
        ConvertNode(root, &pLastNodeInList);

        Node *pHead = pLastNodeInList;
        while (pHead && pHead->left)
        {
            pHead = pHead->left;
        }

        if (pHead && pLastNodeInList)
        {
            pHead->left = pLastNodeInList;
            pLastNodeInList->right = pHead;
        }
        
        return pHead;
    }

    void ConvertNode(Node *pNode, Node **pLastNodeInList)
    {
        if (!pNode)
        {
            return;
        }

        Node *pCurrent = pNode;

        if (pCurrent->left)
        {
            ConvertNode(pCurrent->left, pLastNodeInList);
        }

        pCurrent->left = *pLastNodeInList;
        if (*pLastNodeInList)
        {
            (*pLastNodeInList)->right = pCurrent;
        }

        *pLastNodeInList = pCurrent;

        if (pCurrent->right)
        {
            ConvertNode(pCurrent->right, pLastNodeInList);
        }
    }
};

int main()
{
    Solution solution;

    // Node a(1);
    // Node c(3);
    // Node b(2, &a, &c);
    // Node e(5);
    // Node d(4, &b, &e);

    Node *test = new Node();
    Node *test1 = nullptr;

    Node *result = solution.treeToDoublyList(test1);
    return 0;
}