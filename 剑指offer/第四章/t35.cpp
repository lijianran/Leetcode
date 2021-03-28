
// 2021.03.28
// 剑指offer 第35题
// https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
#include <iostream>

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        cloneNodes(head);
        connectRandomNodes(head);
        return connectNodes(head);
    }

    void cloneNodes(Node *head)
    {
        Node *pNode = head;
        while (pNode)
        {
            Node *pCloneNode = new Node(pNode->val);
            pCloneNode->next = pNode->next;
            pCloneNode->random = nullptr;

            pNode->next = pCloneNode;
            pNode = pCloneNode->next;
        }
    }

    void connectRandomNodes(Node *head)
    {
        Node *pNode = head;
        while (pNode)
        {
            Node *pCloneNode = pNode->next;
            if (pNode->random)
            {
                pCloneNode->random = pNode->random->next;
            }
            pNode = pCloneNode->next;
        }
    }

    Node *connectNodes(Node *head)
    {
        Node *pNode = head;
        Node *pCloneHead = nullptr;
        Node *pCloneNode = nullptr;

        if (pNode)
        {
            pCloneHead = pCloneNode = pNode->next;

            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }

        while (pNode)
        {
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;

            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }

        return pCloneHead;
    }
};

int main()
{
    Solution solution;

    Node a(7);
    Node b(13);
    Node c(11);
    Node d(10);
    Node e(1);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    a.random = nullptr;
    b.random = &a;
    c.random = &e;
    d.random = &c;
    e.random = &a;

    Node *result = solution.copyRandomList(&a);

    return 0;
}