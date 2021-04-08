
// 2021.04.08
// 剑指offer 第52题
// https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unsigned int length1 = getListLength(headA);
        unsigned int length2 = getListLength(headB);
        int lengthDiff = length1 - length2;

        ListNode *pLong = headA;
        ListNode *pShort = headB;

        if (length1 < length2)
        {
            pLong = headB;
            pShort = headA;
            lengthDiff = length2 - length1;
        }

        for (int i = 0; i < lengthDiff; i++)
        {
            pLong = pLong->next;
        }

        while (pLong && pShort && pLong != pShort)
        {
            pLong = pLong->next;
            pShort = pShort->next;
        }
        
        ListNode *pResult = pLong;

        return pResult;
    }

    unsigned int getListLength(ListNode *list)
    {
        unsigned int length = 0;
        ListNode *pNode = list;
        while (pNode)
        {
            ++length;
            pNode = pNode->next;
        }
        return length;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *a = nullptr;
    ListNode *b = nullptr;

    ListNode *result = solution.getIntersectionNode(a, b);
    return 0;
}
