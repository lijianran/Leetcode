
// 2021.06.11
// Leetcode 第 142 题
// https://leetcode-cn.com/problems/linked-list-cycle-ii/

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 双指针
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return nullptr;
        ListNode *n1 = head;
        ListNode *n2 = head;
        // while (n1->next && n1->next->next)  [1,2] -1 WA
        while (n1 && n1->next)
        {
            n1 = n1->next->next;
            n2 = n2->next;
            if (n1 == n2)
                break;
        }

        if (n1 != n2)
        {
            return nullptr;
        }
        n1 = head;
        while (n1 != n2)
        {
            n2 = n2->next;
            n1 = n1->next;
        }
        return n1;
    }
};

int main(int argc, char const *argv[])
{
    // ListNode *a = new ListNode(3);
    // ListNode *b = new ListNode(2);
    // ListNode *c = new ListNode(0);
    // ListNode *d = new ListNode(-4);
    // a->next = b;
    // b->next = c;
    // c->next = d;
    // d->next = b;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    a->next = b;

    Solution solution;
    ListNode *result = solution.detectCycle(a);

    return 0;
}
