
// 2021.03.23
// 剑指offer 第25题
// https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1==nullptr)
        {
            return l2;
        }
        else if(l2==nullptr)
        {
            return l1;
        }

        ListNode *mergeHead = nullptr;

        if (l1->val<l2->val)
        {
            mergeHead = l1;
            mergeHead->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            mergeHead = l2;
            mergeHead->next = mergeTwoLists(l1, l2->next);
        }
        
        return mergeHead; 
    }
};

int main()
{
    Solution solution;

    ListNode a(1);
    ListNode b(2);
    ListNode c(4);
    ListNode d(1);
    ListNode e(3);
    ListNode f(4);
    
    a.next = &b;
    b.next = &c;

    d.next = &e;
    e.next = &f;


    ListNode *result = solution.mergeTwoLists(&a, &d);

    return 0;
}
