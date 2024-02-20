/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include "General.h"

// @lc code=start
class Solution
{
private:
    int state(int num)
    {
        int result = 0;
        if (num < 0)
            result = -1;
        else if (num == 0)
            result = 0;
        else if (num > 0)
            result = 1;
        return result;
    }

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int curr_sum = nums[i] + nums[j] + nums[k];
                switch (state(curr_sum))
                {
                case -1:
                    j++;
                    break;
                case 0:
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                    {
                        j++;
                    } 
                    while (j < k && nums[k] == nums[k - 1]) 
                    {
                        k--;
                    } 
                    j++;
                    k--;
                    break;
                case 1:
                    k--;
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);
    for (const auto &triplet : result)
    {
        cout << "[";
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
