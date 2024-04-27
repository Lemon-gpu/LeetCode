/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

#include "General.h"

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> up = vector<int> (nums.size(), 1);
        vector<int> down = vector<int> (nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            int differ = nums[i] - nums[i - 1];
            if (differ > 0)
            {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            }
            else if (differ < 0)
            {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            }
            else
            {
                down[i] = down[i - 1];
                up[i] = up[i - 1];
            }
        }
        return max(*up.rbegin(), *down.rbegin());
    }
};
// @lc code=end

