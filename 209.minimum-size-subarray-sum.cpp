/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */
#include "General.h"

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int> nums) {
        int result = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum < target)
            {
                continue;
            }
            else
            {
                int curr_result = i - left + 1;
                for (left; left <= i; left++)
                {
                    sum -= nums[left];
                    if (sum < target)
                    {
                        sum += nums[left];
                        break;
                    }
                    curr_result--;
                }
                result = min(result, curr_result);
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.minSubArrayLen(11, {1,1,1,1,1,1,1,1});
    return 0;
}

