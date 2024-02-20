/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

#include "General.h"

// @lc code=start
class Solution
{
    enum Status
    {
        RIGHT,
        DOWN,
        LEFT,
        UP
    };
    Status curr_status = RIGHT;
    vector<vector<int>> matrix;

private:
    pair<int, int> right(pair<int, int> index)
    {
        index.second++;
        return index;
    }
    pair<int, int> down(pair<int, int> index)
    {
        index.first++;
        return index;
    }
    pair<int, int> left(pair<int, int> index)
    {
        index.second--;
        return index;
    }
    pair<int, int> up(pair<int, int> index)
    {
        index.first--;
        return index;
    }

    Status next_status(pair<int, int> index)
    {
        pair<int, int> test_index = next_index(index, this->curr_status);

        if (in_boundary(test_index, this->matrix.size(), this->matrix[0].size()))
            return this->curr_status;
        else
            return Status((this->curr_status + 1) % 4);
    }

    pair<int, int> next_index(pair<int, int> index, Status status)
    {
        switch (status)
        {
        case RIGHT:
            index = right(index);
            break;
        case DOWN:
            index = down(index);
            break;
        case LEFT:
            index = left(index);
            break;
        case UP:
            index = up(index);
            break;
        default:
            break;
        }

        return index;
    }

    bool in_boundary(pair<int, int> index, int m, int n)
    {
        bool condition_1 = index.first >= 0 && index.first < m;
        bool condition_2 = index.second >= 0 && index.second < n;
        bool condition_3 = false;
        if (condition_1 && condition_2)
        {
            condition_3 = this->matrix[index.first][index.second] != INT_MIN;
        }
        return condition_1 && condition_2 && condition_3;
    }

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        pair<int, int> index = {0, 0};
        vector<int> result = {};
        this->matrix = matrix;
        for (int i = 0; i < matrix.size() * matrix[0].size(); i++)
        {
            result.push_back(this->matrix[index.first][index.second]);
            this->matrix[index.first][index.second] = INT_MIN;
            this->curr_status = this->next_status(index);
            index = this->next_index(index, this->curr_status);
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    // Test case
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution solution;
    vector<int> result = solution.spiralOrder(matrix);
    
    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

