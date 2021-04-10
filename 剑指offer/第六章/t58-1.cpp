
// 2021.04.10
// 剑指offer 第58题(1)
// https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
#include <iostream>
#include <string>
using std::string;

class Solution
{
public:
    string reverseWords(string s)
    {
        int length = s.size();
        if (length <= 1)
        {
            if (s[0] == ' ')
            {
                return "";
            }
            
            return s;
        }
        int begin = 0;
        int end = 0;

        string str;
        int p = 0;
        bool flag = (s[0] == ' ') ? false : true;

        while (p != length)
        {
            if (s[p] == ' ' && !flag)
            {
                if (str.size() == 0)
                {
                    p++;
                    continue;
                }
                str += s[p];
                p++;
                flag = !flag;
            }
            else
            {
                if (s[p] == ' ')
                {
                    p++;
                    continue;
                }

                str += s[p];
                p++;
                if (flag)
                {
                    flag = !flag;
                }
            }
        }
        if (str[str.size() - 1] == ' ')
        {
            str.erase(str.end() - 1);
        }

        s = str;
        length = s.size();

        reverse(s, 0, length - 1);

        while (begin != length)
        {
            if (s[begin] == ' ')
            {
                begin++;
                end++;
            }
            else if (s[end] == ' ' || end == length)
            {
                reverse(s, begin, --end);
                begin = ++end;
            }
            else
            {
                end++;
            }
        }

        return s;
    }

    void reverse(string &s, int begin, int end)
    {
        while (begin < end)
        {
            char temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;

            begin++;
            end--;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string test1 = "the sky is blue";
    string test2 = "  hello world!  ";
    string test3 = "    ";
    std::cout << '\"' << solution.reverseWords(test3) << '\"' << std::endl;
    return 0;
}
