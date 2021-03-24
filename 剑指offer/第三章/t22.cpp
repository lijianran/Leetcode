
// 2021.03.23
// 剑指offer 第22题
// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
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
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        if (head == nullptr || k == 0)
        {
            return nullptr;
        }

        ListNode *pHead = head;
        ListNode *pBehind = nullptr;

        for (int i = 0; i < k-1; i++)
        {
            if (pHead->next != nullptr)
            {
                pHead = pHead->next;
            }
            else
            {
                return nullptr;
            }
        }
        
        pBehind = head;

        while (pHead->next != nullptr)
        {
            pHead = pHead->next;
            pBehind = pBehind->next;
        }

        return pBehind;
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

    ListNode *result = solution.getKthFromEnd(&a, 2);

    return 0;
}