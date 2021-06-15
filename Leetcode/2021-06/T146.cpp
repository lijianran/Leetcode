
// 2021.06.15
// Leetcode 第 146 题
// https://leetcode-cn.com/problems/lru-cache/

#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache
{
public:
    LRUCache(int capacity) : m_capacity(capacity)
    {
    }

    int get(int key)
    {
        auto it = m_table.find(key);
        if (it != m_table.end())
        {
            m_LRU.splice(m_LRU.begin(), m_LRU, it->second);
            return it->second->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto it = m_table.find(key);
        if (it != m_table.end())
        {
            m_LRU.splice(m_LRU.begin(), m_LRU, it->second);
            it->second->second = value;
            return;
        }

        // 在开头添加一个元素，对应操作 push_front()，C++11 新增，可以减少内存拷贝和移动
        m_LRU.emplace_front(key, value);
        m_table[key] = m_LRU.begin();

        if (m_table.size() > m_capacity)
        {
            m_table.erase(m_LRU.back().first);
            m_LRU.pop_back();
        }
    }

private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_table;
    std::list<std::pair<int, int>> m_LRU;
    int m_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */