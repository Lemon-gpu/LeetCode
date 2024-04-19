/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] Subsets II
 */

#include "General.h"

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tempResult;

    void search(const vector<int>& nums, int left)
    {
        result.push_back(tempResult);

        if (nums.size() == left) { return; }

        for (int i = left; i < nums.size(); i++)
        {
            if (i != left && nums[i] == nums[i - 1]) { continue; }
            tempResult.push_back(nums[i]);
            search(nums, i + 1);
            tempResult.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        search(nums, 0);
        return result;
    }
};
// @lc code=end

