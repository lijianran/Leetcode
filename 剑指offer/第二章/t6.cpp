
// 2021.03.09
// 剑指offer 第6题
// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
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
    vector<int> reversePrint(ListNode *head)
    {
        if (head == nullptr)
        {
            return {};
        }
        vector<int> returnData = reversePrint(head->next);
        returnData.push_back(head->val);
        return returnData;
    }
};

int main()
{
    Solution solution;

    ListNode head(1);
    ListNode node1(3);
    ListNode node2(2);

    head.next = &node1;
    node1.next = &node2;
    // node2.next = NULL;

    ListNode *test = NULL;

    vector<int> result = solution.reversePrint(&head);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}