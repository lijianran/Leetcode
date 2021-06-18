
// 2021.06.18
// Leetcode 第 207 题
// https://leetcode-cn.com/problems/course-schedule/

#include <iostream>
#include <vector>
#include <queue>
using std::vector;

// DFS
class Solution
{
private:
    std::vector<std::vector<int>> m_edges;
    // 0-待搜索 1-正搜索 2-已搜索
    std::vector<int> visited;
    // canFinish   无环
    bool valid = true;

protected:
    void dfs(int u)
    {
        // 开始搜索节点 u
        visited[u] = 1;
        for (int v : m_edges[u])
        {
            if (visited[v] == 0)
            {
                dfs(v);
                if (!valid)
                    return;
            }
            else if (visited[v] == 1)
            {
                // 有环
                valid = false;
                return;
            }
        }
        // 节点 u 已经搜索完成
        visited[u] = 2;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        m_edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto &c : prerequisites)
        {
            m_edges[c[1]].push_back(c[0]);
        }
        for (int course = 0; course < numCourses && valid; ++course)
        {
            if (!visited[course])
            {
                dfs(course);
            }
        }
        return valid;
    }
};

// BFS
class Solution2
{
private:
    std::vector<std::vector<int>> m_edges;
    // 入度
    std::vector<int> m_indegree;

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        m_edges.resize(numCourses);
        m_indegree.resize(numCourses);
        // 计算入度
        for (const auto &c : prerequisites)
        {
            m_edges[c[1]].push_back(c[0]);
            ++m_indegree[c[0]];
        }

        std::queue<int> q;
        // 将入度为 0 的节点存入队列
        for (int course = 0; course < numCourses; ++course)
        {
            if (m_indegree[course] == 0)
            {
                q.push(course);
            }
        }

        // 统计访问个数
        int visited = 0;
        while (!q.empty())
        {
            ++visited;
            int course = q.front();
            q.pop();
            for (const int v : m_edges[course])
            {
                --m_indegree[v];
                if (m_indegree[v] == 0)
                {
                    // 入度为 0，存入队列
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};
