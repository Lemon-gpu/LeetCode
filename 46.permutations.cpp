/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] Permutations
 */
#include "General.h"

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tempResult;
    
    void search(vector<int>& nums)
    {
        if (tempResult.size() == nums.size())
        {
            result.push_back(tempResult);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == INT_MIN) { continue; }
            int num = nums[i];

            tempResult.push_back(num);
            nums[i] = INT_MIN;
            search(nums);
            nums[i] = num;
            tempResult.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        search(nums);
        return result;
    }
};
// @lc code=end

