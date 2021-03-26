
// 2021.03.26
// 剑指offer 第30题
// https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
#include <iostream>
#include <stack>

class MinStack
{
private:
    std::stack<int> m_data;
    std::stack<int> m_min;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        m_data.push(x);

        if (m_min.size() == 0 || x < m_min.top())
        {
            m_min.push(x);
        }
        else
        {
            m_min.push(m_min.top());
        }
    }

    void pop()
    {
        if (m_data.size() > 0 && m_data.size() > 0)
        {
            m_data.pop();
            m_min.pop();
        }
    }

    int top()
    {
        return m_data.top();
    }

    int min()
    {
        return m_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main()
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << minStack->min();
    minStack->pop();
    std::cout << minStack->top();
    std::cout << minStack->min();
    return 0;
}