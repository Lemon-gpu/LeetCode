/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
#include "General.h"

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tempResult;

    void search(vector<int>& candidates, int target, int left)
    {
        if (target < 0) { return; }
        if (target == 0) { result.push_back(tempResult); return; }

        for (int i = left; i < candidates.size(); i++)
        {
            if (candidates[i] > target) { break; }
            if (i > left && candidates[i] == candidates[i - 1]) { continue; }

            tempResult.push_back(candidates[i]);
            search(candidates, target - candidates[i], i + 1);
            tempResult.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        search(candidates, target, 0);
        return result;
    }
};
// @lc code=end

