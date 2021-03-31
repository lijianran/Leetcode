
// 2021.03.31
// 剑指offer 第41题
// https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if ((m_Min.size() + m_Max.size()) % 2 == 0)
        {
            if (m_Max.size() > 0 && num < m_Max[0])
            {
                m_Max.push_back(num);
                std::push_heap(m_Max.begin(), m_Max.end(), std::less<int>());

                num = m_Max[0];

                std::pop_heap(m_Max.begin(), m_Max.end(), std::less<int>());
                m_Max.pop_back();
            }

            m_Min.push_back(num);
            std::push_heap(m_Min.begin(), m_Min.end(), std::greater<int>());
        }
        else
        {
            if (m_Min.size() > 0 && m_Min[0] < num)
            {
                m_Min.push_back(num);
                std::push_heap(m_Min.begin(), m_Min.end(), std::greater<int>());

                num = m_Min[0];

                std::pop_heap(m_Min.begin(), m_Min.end(), std::greater<int>());
                m_Min.pop_back();
            }

            m_Max.push_back(num);
            std::push_heap(m_Max.begin(), m_Max.end(), std::less<int>());
        }
    }

    double findMedian()
    {
        int size = m_Max.size() + m_Min.size();

        if (size == 0)
        {
            return 0;
        }

        double median = 0;
        if (size % 2 == 1)
        {
            median = m_Min[0];
        }
        else
        {
            median = (m_Min[0] + m_Max[0]) / 2.0;
        }

        return median;
    }

private:
    std::vector<int> m_Min;
    std::vector<int> m_Max;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, char const *argv[])
{
    MedianFinder medianfinder;

    std::cout << medianfinder.findMedian() << std::endl;
    medianfinder.addNum(1);
    medianfinder.addNum(2);
    std::cout << medianfinder.findMedian() << std::endl;
    medianfinder.addNum(3);
    std::cout << medianfinder.findMedian() << std::endl;

    return 0;
}
