
// 2021.06.15
// Leetcode 第 148 题
// https://leetcode-cn.com/problems/sort-list/
/*
问题要求达到 
O(nlogn) 的时间复杂度和 
O(1) 的空间复杂度，
时间复杂度是 O(nlogn) 的排序算法包括归并排序、堆排序和快速排序（快速排序的最差时间复杂度是O(n^2)）
最适合链表的排序算法是归并排序
*/

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// // 冒泡，超时
// class Solution
// {
// public:
//     ListNode *sortList(ListNode *head)
//     {
//         if (!head || !head->next)
//             return head;

//         while (true)
//         {
//             bool flag = false;
//             ListNode *pre = nullptr;
//             ListNode *cur = head;
//             while (cur->next)
//             {
//                 if (cur->val > cur->next->val)
//                 {
//                     ListNode *temp = cur->next;
//                     cur->next = temp->next;
//                     temp->next = cur;
//                     if (!pre)
//                     {
//                         // pre = temp;
//                         head = temp;
//                     }
//                     else
//                     {
//                         pre->next = temp;
//                     }
//                     flag = true;
//                 }
//                 else
//                 {
//                     cur = cur->next;
//                 }

//                 if (!pre)
//                 {
//                     pre = head;
//                 }
//                 else
//                 {
//                     pre = pre->next;
//                 }
//             }
//             if (!flag)
//                 break;
//         }

//         return head;
//     }
// };

// 归并，最适合链表的排序算法是归并排序
// 自底向上
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        int length = 0;
        ListNode *node = head;
        while (node)
        {
            ++length;
            node = node->next;
        }

        ListNode *dummyHead = new ListNode(0, head);

        for (int subLength = 1; subLength < length; subLength <<= 1)
        {
            ListNode *pre = dummyHead;
            ListNode *cur = dummyHead->next;
            while (cur)
            {
                ListNode *head1 = cur;
                for (int i = 1; i < subLength && cur->next; ++i)
                {
                    cur = cur->next;
                }
                ListNode *head2 = cur->next;
                cur->next = nullptr;
                cur = head2;

                for (int i = 1; i < subLength && cur && cur->next; ++i)
                {
                    cur = cur->next;
                }

                ListNode *next = nullptr;
                if (cur)
                {
                    next = cur->next;
                    cur->next = nullptr;
                }

                ListNode *merged = merge(head1, head2);
                pre->next = merged;
                while (pre->next)
                {
                    pre = pre->next;
                }
                cur = next;
            }
        }
        return dummyHead->next;
    }

protected:
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *head = new ListNode();
        ListNode *cur = head;
        ListNode *n1 = head1;
        ListNode *n2 = head2;
        while (n1 && n2)
        {
            if (n1->val <= n2->val)
            {
                cur->next = n1;
                n1 = n1->next;
            }
            else
            {
                cur->next = n2;
                n2 = n2->next;
            }
            cur = cur->next;
        }

        if (n1)
        {
            cur->next = n1;
        }
        if (n2)
        {
            cur->next = n2;
        }
        return head->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *a = new ListNode(4);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(1);
    ListNode *d = new ListNode(3);
    a->next = b;
    b->next = c;
    c->next = d;

    Solution solution;
    ListNode *result = solution.sortList(a);

    return 0;
}
