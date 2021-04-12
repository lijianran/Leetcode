
// 2021.04.12
// 剑指offer 第64题
// https://leetcode-cn.com/problems/qiu-12n-lcof/
#include <iostream>

class Temp
{
public:
    Temp()
    {
        ++N;
        Sum += N;
    }

    static void Reset()
    {
        N = 0;
        Sum = 0;
    }

    static int GetSum()
    {
        return Sum;
    }

private:
    static int N;
    static int Sum;
};

int Temp::N = 0;
int Temp::Sum = 0;

class Solution
{
public:
    int sumNums(int n)
    {
        Temp::Reset();

        Temp *a = new Temp[n];
        delete[] a;
        a = nullptr;

        return Temp::GetSum();
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    std::cout << solution.sumNums(9) << std::endl;
    return 0;
}
