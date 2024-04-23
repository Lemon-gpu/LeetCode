/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] Permutations II
 */
#include "General.h"

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tempResult;

    void search(vector<int>& nums)
    {
        if (nums.size() == tempResult.size())
        {
            result.push_back(tempResult);
            return;
        }

        unordered_set<int> used;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (used.find(num) != used.end() || num == INT_MIN)
            {
                continue;
            }
            used.insert(num);

            nums[i] = INT_MIN;
            tempResult.push_back(num);
            search(nums);
            tempResult.pop_back();
            nums[i] = num;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        search(nums);
        return result;
    }
};
// @lc code=end

