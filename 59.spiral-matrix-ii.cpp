/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
#include "General.h"

// @lc code=start
class Solution {
    enum Status { RIGHT, DOWN, LEFT, UP };
    Status curr_status = RIGHT;
    vector<vector<int>> matrix;

private:
    pair<int, int> right(pair<int, int> index) { index.second++; return index;}
    pair<int, int> down(pair<int, int> index) { index.first++; return index;}
    pair<int, int> left(pair<int, int> index) { index.second--; return index;}
    pair<int, int> up(pair<int, int> index) { index.first--; return index;}

    Status next_status(pair<int, int> index)
    {
        pair<int, int> test_index = next_index(index, this->curr_status);

        if (in_boundary(test_index, this->matrix.size()))
            return this->curr_status;
        else
            return Status((this->curr_status + 1) % 4);
    }

    pair<int, int> next_index(pair<int, int> index, Status status) 
    {
        switch (status)
        {
        case RIGHT: index = right(index); break;
        case DOWN: index = down(index); break;
        case LEFT: index = left(index); break;
        case UP: index = up(index); break;
        default: break;
        }

        return index;
    }

    bool in_boundary(pair<int, int> index, int n)
    {
        bool condition_1 = index.first >= 0 && index.first < n;
        bool condition_2 = index.second >= 0 && index.second < n;
        bool condition_3 = false;
        if (condition_1 && condition_2) { condition_3 = this->matrix[index.first][index.second] == 0; }
        return condition_1 && condition_2 && condition_3;
    }

public:
    vector<vector<int>> generateMatrix(const int n) 
    {
        pair<int, int> index = {0, 0};
        matrix = matrix = vector<vector<int>>(n, vector<int>(n, 0));
        for(int i = 1; i <= n * n; i++)
        {
            this->matrix[index.first][index.second] = i;
            this->curr_status = next_status(index);
            index = next_index(index, this->curr_status);
        }
        return this->matrix;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    auto a = s.generateMatrix(1);
    cout << "debug";
    return 0;
}


