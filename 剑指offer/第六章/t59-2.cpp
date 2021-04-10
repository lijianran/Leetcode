
// 2021.04.10
// 剑指offer 第59题(2)
// https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
#include <iostream>
#include <queue>

class MaxQueue
{
public:
    MaxQueue()
    {
        currentIndex = 0;
    }

    int max_value()
    {
        if (max.empty())
        {
            return -1;
        }

        return max.front().value;
    }

    void push_back(int value)
    {
        while (!max.empty() && value >= max.back().value)
        {
            max.pop_back();
        }

        InternalData internalData = {value, currentIndex};
        data.push_back(internalData);
        max.push_back(internalData);

        ++currentIndex;
    }

    int pop_front()
    {
        if (max.empty())
        {
            return -1;
        }
        if (max.front().index == data.front().index)
        {
            max.pop_front();
        }

        int popData = data.front().value;
        data.pop_front();
        return popData;
    }

private:
    struct InternalData
    {
        int value;
        int index;
    };

    std::deque<InternalData> data;
    std::deque<InternalData> max;
    int currentIndex;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main(int argc, char const *argv[])
{
    MaxQueue *obj = new MaxQueue();
    int param_1 = obj->max_value();
    obj->push_back(1);
    obj->push_back(2);

    int param_3 = obj->pop_front();

    return 0;
}
