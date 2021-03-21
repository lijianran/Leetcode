
// 2021.03.21
// 剑指offer 第19题
// https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        // if (s.empty() || p.empty())
        // {
        //     return false;
        // }

        return matchCore(s, p);
    }

    // bool matchCore(string s, string p, int a, int b)
    // {
    //     if (a == s.size() && b == p.size())
    //     {
    //         return true;
    //     }

    //     if (a < s.size() && b >= p.size())
    //     {
    //         return false;
    //     }

    //     if (p[b + 1] == '*')
    //     {
    //         if (s[a] == p[b] || (p[b] == '.' && !s.empty()))
    //         {
    //             return matchCore(s, p, a + 1, b + 2) || matchCore(s, p, a + 1, b) || matchCore(s, p, a, b + 2);
    //         }
    //         else
    //         {
    //             return matchCore(s, p, a, b + 2);
    //         }
    //     }

    //     if (s[a] == p[b] || (p[b] == '.' && !s.empty()))
    //     {
    //         return matchCore(s, p, a + 1, b + 1);
    //     }

    //     return false;
    // }
    
    bool matchCore(string s, string p)
    {
        if (s.empty() && p.empty())
        {
            return true;
        }

        if (!s.empty() &&p.empty())
        {
            return false;
        }

        if (p[1] == '*')
        {
            if (s[0] == p[0] || (p[0] == '.' && !s.empty()))
            {
                return matchCore(s.substr(1), p.substr(2)) || matchCore(s.substr(1), p) || matchCore(s, p.substr(2));
            }
            else
            {
                return matchCore(s, p.substr(2));
            }
        }

        if (s[0] == p[0] || (p[0] == '.' && !s.empty()))
        {
            return matchCore(s.substr(1), p.substr(1));
        }

        return false;
    }
};

int main()
{
    Solution solution;
    // cout << solution.isMatch("aa", "a") << endl;
    // cout << solution.isMatch("aa", "a*") << endl;
    // cout << solution.isMatch("ab", ".*") << endl;
    // cout << solution.isMatch("aab", "c*a*b") << endl;
    // cout << solution.isMatch("mississippi", "mis*is*p*.") << endl;

    // cout << solution.isMatch("aaa", "a.a") << endl;
    // cout << solution.isMatch("aaa", "ab*ac*a") << endl;
    // cout << solution.isMatch("aaa", "aa.a") << endl;
    // cout << solution.isMatch("aaa", "ab*a") << endl;


    // cout << solution.isMatch("ab", ".*c") << endl;

    // cout << solution.isMatch("", ".*") << endl;
    
    cout << solution.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") << endl;

    // string a = "1234";
    // string b = &a[4];
    // string c = a.substr(1);
    return 0;
}