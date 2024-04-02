/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] Combinations
 */
#include "General.h"

// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    void backtracking(int currIteration, int maxIteration, vector<int>& currResult, int left, int right)
    {
        if (currIteration >= maxIteration) { result.push_back(currResult); return; }
        if (right - left < maxIteration - currIteration) { return; } // 剪枝(剩余元素不够

        for (; left < right; left++)
        {
            currResult.push_back(left + 1);
            backtracking(currIteration + 1, maxIteration, currResult, left + 1, right);
            currResult.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        backtracking(0, k, temp, 0, n);
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> result = s.combine(4, 2);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}
