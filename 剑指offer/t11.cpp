
// 2021.03.13
// 剑指offer 第11题
// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int length = numbers.size();

        if (length == 0)
        {
            return -1;
        }
        

        int index1 = 0;
        int index2 = length - 1;
        int indexMid = index1;

        while (numbers[index1] >= numbers[index2])
        {
            // 下标相邻，index2就是结果
            if (index2 - index1 == 1)
            {
                indexMid = index2;
                break;
            }

            // 二分中值
            indexMid = (index1 + index2) / 2;

            // 判断第一个数、最后一个数、中间的数是否相同，如果相同则只能遍历查询最小值
            if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid])
            {
                return minInOrder(numbers, index1, index2);
            }

            // 如果中间值大于第一个值，更新index1；如果中间值小于最后一个值，则更新index2
            if (numbers[indexMid] >= numbers[index1])
            {
                index1 = indexMid;
            }
            else if (numbers[indexMid] <= numbers[index2])
            {
                index2 = indexMid;
            }
        }
        return numbers[indexMid];
    }

    int minInOrder(vector<int> &numbers, int index1, int index2)
    {
        // 循环遍历index1到index2，找到最小值
        int result = numbers[index1];
        for (int i = index1 + 1; i <= index2; i++)
        {
            if (result > numbers[i])
            {
                result = numbers[i];
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;

    vector<int> test1 = {3, 4, 5, 1, 2};
    vector<int> test2 = {2, 2, 2, 0, 1};

    vector<int> test3 = {1, 0, 1, 1, 1};
    vector<int> test4 = {1, 1, 1, 0, 1};

    vector<int> test5 = {19};
    vector<int> test6;


    cout << solution.minArray(test6) << endl;

    return 0;
}
