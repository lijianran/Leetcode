
// 2021.07.01
// Leetcode 第 394 题
// https://leetcode-cn.com/problems/decode-string/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using std::string;

// 栈
class Solution
{
public:
    string decodeString(string s)
    {
        if (s.size() < 0)
            return "";
        std::stack<char> st;
        for (const char c : s)
        {
            if (c != ']')
            {
                st.push(c);
            }
            else
            {
                std::string temp;
                char ch = st.top();
                st.pop();
                while (ch != '[')
                {
                    temp = ch + temp;
                    ch = st.top();
                    st.pop();
                }
                ch = st.top();
                std::string numstr;
                while (st.size() > 0 && ch <= 57 && ch >= 48)
                {
                    numstr = ch + numstr;
                    st.pop();
                    if (st.size() > 0)
                        ch = st.top();
                }
                int num = std::atoi(numstr.c_str());
                for (int i = 0; i < num; ++i)
                {
                    for (const char tempc : temp)
                    {
                        st.push(tempc);
                    }
                }
            }
        }
        std::string res;
        while (st.size())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

int main(int argc, const char *argv[])
{
    Solution solution;
    std::cout << solution.decodeString("100[leetcode]") << std::endl;
    return 0;
}
