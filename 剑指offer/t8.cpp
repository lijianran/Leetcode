
// 2021.03.11
// 剑指offer 第9题
// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
#include <iostream>
#include <stack>
using namespace std;

class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        stack1.push(value);
    }

    int deleteHead()
    {
        if (stack2.size() <= 0)
        {
            while (stack1.size() > 0)
            {
                int data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }

        if (stack2.size() == 0)
        {
            return -1;
        }

        int head = stack2.top();
        stack2.pop();

        return head;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
    CQueue *obj = new CQueue();
    obj->appendTail(5);
    obj->appendTail(2);
    int param_2 = obj->deleteHead();
    cout << param_2 << endl;

    param_2 = obj->deleteHead();
    cout << param_2 << endl;


    return 0;
}