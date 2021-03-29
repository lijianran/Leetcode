
// 2021.03.29
// 剑指offer 第40题
// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        int length = arr.size();
        if (k <= 0 || length == 0)
        {
            return {};
        }
        if (k == length)
        {
            return arr;
        }

        int start = 0;
        int end = length - 1;
        int index = Partition(arr, length, start, end);
        while (index != k - 1)
        {
            if (index > k - 1)
            {
                end = index - 1;
                index = Partition(arr, length, start, end);
            }
            else
            {
                start = index + 1;
                index = Partition(arr, length, start, end);
            }
        }

        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(arr[i]);
        }
        return result;
    }

    int Partition(vector<int> &arr, int length, int start, int end)
    {
        int small = start - 1;
        for (int index = start; index < end; index++)
        {
            if (arr[index] < arr[end])
            {
                ++small;
                if (small != index)
                { // arr[small]的值大，和当前index的值互换
                    int temp = arr[index];
                    arr[index] = arr[small];
                    arr[small] = temp;
                }
            }
        }

        ++small;
        int temp = arr[end];
        arr[end] = arr[small];
        arr[small] = temp;

        return small;
    }
};

int main()
{
    Solution solution;
    vector<int> arr1 = {3, 2, 1};
    vector<int> arr2 = {0, 1, 2, 1};
    vector<int> arr3 = {4, 5, 1, 6, 2, 7, 3, 8};

    vector<int> result = solution.getLeastNumbers(arr3, 4);

    return 0;
}