
// 2021.06.03
// Leetcode 第 23 题
// https://leetcode-cn.com/problems/merge-k-sorted-lists/

#include <iostream>
#include <vector>
#include <queue>
using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 原地拼接，但耗时
// class Solution
// {
// public:
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         if (lists.empty())
//             return nullptr;

//         ListNode *head = nullptr;
//         ListNode *node = nullptr;

//         while (true)
//         {
//             // 找一个不为空的链表
//             int s = 0;
//             while (!lists[s] && s < lists.size())
//             {
//                 ++s;
//             }
//             // 链表全为空，合并结束
//             if (s == lists.size())
//                 break;

//             // 找最小的节点
//             int min = lists[s]->val;
//             int index = s;
//             for (int i = 0; i < lists.size(); ++i)
//             {
//                 // 链表为空
//                 if (!lists[i])
//                 {
//                     continue;
//                 }
//                 // 找到更小的节点，更新最小值和序号
//                 if (lists[i]->val < min)
//                 {
//                     min = lists[i]->val;
//                     index = i;
//                 }
//             }

//             // 取出链表
//             auto phead = lists[index];
//             if (!head)
//             {
//                 // 如果是第一个节点
//                 head = phead;
//                 lists[index] = head->next;
//                 head->next = nullptr;
//                 node = head;
//             }
//             else
//             {
//                 // 后续节点，连接到 head
//                 node->next = phead;
//                 node = node->next;
//                 lists[index] = node->next;
//                 node->next = nullptr;
//             }
//         }

//         return head;
//     }
// };

class Solution
{
public:
    struct Status
    {
        int val;
        ListNode *ptr;
        bool operator<(const Status &rhs) const
        {
            return val > rhs.val;
        }
    };

    std::priority_queue<Status> queue;

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        for (auto &node : lists)
        {
            if (node)
            {
                queue.push({node->val, node});
            }
        }
        ListNode head;
        ListNode *node = &head;
        while (!queue.empty())
        {
            auto pnode = queue.top();
            queue.pop();
            node->next = pnode.ptr;
            node = node->next;
            if (pnode.ptr->next)
            {
                queue.push({pnode.ptr->next->val, pnode.ptr->next});
            }
        }
        return head.next;
    }
};

int main(int argc, char const *argv[])
{
    // [1,4,5],[1,3,4],[2,6]
    Solution solution;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(4);
    ListNode *c = new ListNode(5);
    ListNode *d = new ListNode(1);
    ListNode *e = new ListNode(3);
    ListNode *f = new ListNode(4);
    ListNode *g = new ListNode(2);
    ListNode *h = new ListNode(6);

    a->next = b;
    b->next = c;

    d->next = e;
    e->next = f;

    g->next = h;

    vector<ListNode *> lists;
    lists.push_back(a);
    lists.push_back(d);
    lists.push_back(g);

    auto result = solution.mergeKLists(lists);

    return 0;
}
