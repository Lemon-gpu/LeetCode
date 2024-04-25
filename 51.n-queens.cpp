/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N-Queens
 */

#include "General.h"

// @lc code=start
class Solution {
private:
    list<vector<vector<bool>>> tempResult;
    vector<vector<bool>> board;

    bool inside(const pair<int, int>& index, const vector<vector<bool>>& board)
    {
        if (index.first >= 0 && index.first < board.size() && index.second >= 0 && index.second < board[0].size())
            return true;
        return false;
    }

    bool availability(const pair<int, int>& index, const vector<vector<bool>>& board)
    {
        // row check
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][index.second] == 1)
                return false;
        }

        //column check
        for (int i = 0; i < board[0].size(); i++)
        {
            if (board[index.first][i] == 1)
                return false;
        }

        //diagonal check
        pair<int, int> tempIndex = index;
        while (inside(tempIndex, board))
        {
            if (board[tempIndex.first][tempIndex.second] == 1)
                return false;
            tempIndex.first--;
            tempIndex.second--;
        }

        tempIndex = index;
        while (inside(tempIndex, board))
        {
            if (board[tempIndex.first][tempIndex.second] == 1)
                return false;
            tempIndex.first++;
            tempIndex.second++;
        }

        tempIndex = index;
        while (inside(tempIndex, board))
        {
            if (board[tempIndex.first][tempIndex.second] == 1)
                return false;
            tempIndex.first--;
            tempIndex.second++;
        }

        tempIndex = index;
        while (inside(tempIndex, board))
        {
            if (board[tempIndex.first][tempIndex.second] == 1)
                return false;
            tempIndex.first++;
            tempIndex.second--;
        }

        return true;
    }
    
    void backtracking(vector<vector<bool>>& board, int row)
    {
        if (row == board.size())
        {
            tempResult.push_back(board);
            return;
        }

        for (int i = 0; i < board[0].size(); i++)
        {
            if (availability({row, i}, board))
            {
                board[row][i] = 1;
                backtracking(board, row + 1);
                board[row][i] = 0;
            }
        }
    }

    vector<string> convert(const vector<vector<bool>>& board)
    {
        vector<string> result;
        for (int i = 0; i < board.size(); i++)
        {
            string temp;
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 1)
                    temp += 'Q';
                else
                    temp += '.';
            }
            result.push_back(temp);
        }
        return result;
    }   

    vector<vector<string>> batchConvert(const list<vector<vector<bool>>>& tempResult)
    {
        vector<vector<string>> result;
        for (auto& board : tempResult)
        {
            result.push_back(convert(board));
        }
        return result;
    }

public:
    vector<vector<string>> solveNQueens(int n) 
    {
        board = vector<vector<bool>>(n, vector<bool>(n, 0));
        backtracking(board, 0);
        return batchConvert(tempResult);
    }
};
// @lc code=end

