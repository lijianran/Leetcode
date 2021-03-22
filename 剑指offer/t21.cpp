
// 2021.03.22
// 剑指offer 第21题
// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int length = nums.size();
        if (length == 0)
        {
            return {};
        }

        int pBegin = 0;
        int pEnd = length - 1;

        while (pBegin < pEnd)
        {
            while (pBegin < pEnd && (nums[pBegin] % 2 != 0))
            {
                pBegin++;
            }

            while (pBegin < pEnd && (nums[pEnd] % 2 == 0))
            {
                pEnd--;
            }

            if (pBegin < pEnd)
            {
                int temp = nums[pBegin];
                nums[pBegin] = nums[pEnd];
                nums[pEnd] = temp;
            }
        }

        return nums;
    }
};

void print(vector<int> nums)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

int main()
{
    Solution solution;
    vector<int> test1 = {1, 2, 3, 4};
    vector<int> test2 = {1, 2, 3, 4, 5};

    print(solution.exchange(test1));
    print(solution.exchange(test2));

    return 0;
}