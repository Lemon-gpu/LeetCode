/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
#include "General.h"

// @lc code=start
class Solution
{
private:

    bool availability(const pair<int, int> &index, const vector<vector<char>> &board, char num)
    {
        // row check
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][index.second] == num)
                return false;
        }

        // column check
        for (int i = 0; i < board[0].size(); i++)
        {
            if (board[index.first][i] == num)
                return false;
        }

        // 3*3 grid check
        int row = index.first / 3 * 3;
        int col = index.second / 3 * 3;
        for (int i = row; i < row + 3; i++)
        {
            for (int j = col; j < col + 3; j++)
            {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool backtracking(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                    continue;
                for (int k = 1; k <= 9; k++)
                {
                    pair<int, int> targetIndex = make_pair(i, j);
                    if (availability(targetIndex, board, k + '0'))
                    {
                        board[i][j] = k + '0';
                        if (backtracking(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }
};
// @lc code=end
