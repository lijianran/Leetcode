
// 2021.06.01
// Leetcode 第 2 题
// https://leetcode-cn.com/problems/add-two-numbers/

#include <iostream>
#include <vector>
using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 第一次做不出来
// class Solution
// {
// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//     {
//         ListNode *n1 = l1;
//         ListNode *n2 = l2;
//         bool flag = false;
//         while (n1->next != nullptr)
//         {
//             if (n2 == nullptr)
//             {
//                 if (flag)
//                 {
//                     ++(n1->val);
//                     if (n1->val >= 10)
//                     {
//                         n1->val -= 10;
//                         flag = true;
//                     }
//                     else
//                     {
//                         flag = false;
//                     }
//                     n1 = n1->next;
//                     if (n1->next == nullptr && flag)
//                     {
//                         ListNode last(1);
//                         n1->next = &last;
//                         flag = false;
//                         return l1;
//                     }
//                     continue;
//                 }
//                 return l1;
//             }
//             int sum = n1->val + n2->val + (flag ? 1 : 0);
//             if (sum < 10)
//             {
//                 n1->val = sum;
//                 flag = false;
//             }
//             else
//             {
//                 n1->val = sum - 10;
//                 flag = true;
//             }
//             n1 = n1->next;
//             n2 = n2->next;
//         }
//         if (n2 != nullptr && n1 != nullptr && n1->next == nullptr)
//         {
//             int sum = n1->val + n2->val + (flag ? 1 : 0);
//             if (sum < 10)
//             {
//                 n1->val = sum;
//                 flag = false;
//             }
//             else
//             {
//                 n1->val = sum - 10;
//                 flag = true;
//             }
//             n1->next = n2;
//             n2 = n2->next;
//             while (n2 != nullptr && flag)
//             {
//                 ++(n2->val);
//                 if (n2->val >= 10)
//                 {
//                     n2->val -= 10;
//                     flag = true;
//                 }
//                 flag = false;
//                 n2 = n2->next;
//             }
//             if (n2 == nullptr && flag)
//             {
//                 ListNode last(1);
//                 n2->next = &last;
//             }
//         }
//         return l1;
//     }
// };

// 新建空间
// class Solution
// {
// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//     {
//         ListNode *head = nullptr;
//         ListNode *tail = nullptr;
//         int carry = 0;
//         int sum = 0;
//         while (l1 || l2)
//         {
//             int val1 = l1 ? l1->val : 0;
//             int val2 = l2 ? l2->val : 0;

//             sum = val1 + val2 + carry;
//             if (!head)
//             {
//                 head = new ListNode(sum % 10);
//                 tail = head;
//             }
//             else
//             {
//                 tail->next = new ListNode(sum % 10);
//                 tail = tail->next;
//             }

//             carry = sum / 10;

//             if (l1)
//             {
//                 l1 = l1->next;
//             }
//             if (l2)
//             {
//                 l2 = l2->next;
//             }
//         }
//         if (carry > 0)
//         {
//             tail->next = new ListNode(carry);
//         }

//         return head;
//     }
// };

// 使用 l1 的空间
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *n1 = l1;
        ListNode *n2 = l2;
        // 先不考虑进位
        while (n1)
        {
            if (n2)
            {
                // n1，n2 都有，直接相加，放到 n1 中
                n1->val = n1->val + n2->val;
            }
            else
            {
                // n1 还有，n2 无
                break;
            }

            if (n1->next == nullptr)
            {
                // n1 无，n2 有，直接将 n2 拼接到 n1 后
                n1->next = n2->next;
                break;
            }

            n1 = n1->next;
            n2 = n2->next;
        }

        // 处理进位
        n1 = l1;
        while (n1->next)
        {
            if (n1->val > 9)
            {
                n1->val = n1->val - 10;
                n1->next->val = n1->next->val + 1;
            }
            n1 = n1->next;
        }

        // 最高位需进位，新建一个节点
        if (n1->val > 9)
        {
            n1->val = n1->val - 10;
            ListNode *last = new ListNode(1);
            n1->next = last;
        }

        return l1;
    }
};