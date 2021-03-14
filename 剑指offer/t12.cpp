
// 2021.03.14
// 剑指offer 第12题
// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {

        if (board.empty() || board[0].empty() || word.empty())
        {
            return false;
        }
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int pathLength = 0;
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (hasPathCore(board, word, visited, row, col, pathLength))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPathCore(const vector<vector<char>> &board, const string word,
                     vector<vector<bool>> &visited, int row, int col, int &pathLength)
    {
        int rows = board.size();
        int cols = board[0].size();

        if (word.size() == pathLength)
        {
            return true;
        }

        bool hasPath = false;
        if (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == word[pathLength] && !visited[row][col])
        {
            ++pathLength;
            visited[row][col] = true;

            hasPath = hasPathCore(board, word, visited, row, col - 1, pathLength) || hasPathCore(board, word, visited, row - 1, col, pathLength) || hasPathCore(board, word, visited, row, col + 1, pathLength) || hasPathCore(board, word, visited, row + 1, col, pathLength);

            if (!hasPath)
            {
                --pathLength;
                visited[row][col] = false;
            }
        }
        return hasPath;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board1 = {
        {'a', 'b'},
        {'c', 'd'},
    };
    string word1 = "abcd";

    vector<vector<char>> board2 = {{'A', 'B', 'C', 'E'},
                                   {'S', 'F', 'C', 'S'},
                                   {'A', 'D', 'E', 'E'}};
    string word2 = "ABCCED";

    vector<vector<char>> board3 = {{'a', 'b', 't', 'g'},
                                   {'c', 'f', 'c', 's'},
                                   {'j', 'd', 'e', 'h'}};
    string word3 = "bfce";

    vector<vector<char>> board4 = {{'a'}};
    string word4 = "ab";

    cout << solution.exist(board4, word4) << endl;

    return 0;
}