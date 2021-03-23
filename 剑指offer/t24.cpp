
// 2021.03.23
// 剑指offer 第24题
// https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pReverseHead = nullptr;
        ListNode *pNode = head;
        ListNode *pPreNode = nullptr;

        while (pNode != nullptr)
        {
            ListNode *pNextNode = pNode->next;

            if (pNextNode == nullptr)
            {
                pReverseHead = pNode;
            }

            pNode->next = pPreNode;

            pPreNode = pNode;
            pNode = pNextNode;
        }
        return pReverseHead;
    }
};

int main()
{
    Solution solution;

    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    ListNode *result = solution.reverseList(&a);

    return 0;
}
