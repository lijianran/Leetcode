
// 2021.03.18
// 剑指offer 第18题
// https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
#include <iostream>
#include <vector>
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
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *pre = nullptr, *cur = head;
        while (cur->val != val)
        {
            pre = cur;
            cur = cur->next;
        }

        if (cur == head)
        {
            head = head->next;
        }
        else
        {
            pre->next = cur->next;
        }

        return head;
    }
};

int main()
{
    ListNode a(4);
    ListNode b(5);
    ListNode c(1);
    ListNode d(9);
    a.next = &b;
    b.next = &c;
    c.next = &d;

    Solution solution;
    ListNode *result = solution.deleteNode(&a, 1);

    return 0;
}