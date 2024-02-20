/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include "General.h"

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int t)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicates for the first number
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; // Skip duplicates for the second number
                int left = j + 1, right = nums.size() - 1;
                while (left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    long long target = t;
                    if (sum < target)
                    {
                        ++left;
                    }
                    else if (sum > target)
                    {
                        --right;
                    }
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            ++left; // Skip duplicates
                        while (left < right && nums[right] == nums[right - 1])
                            --right; // Skip duplicates
                        ++left;
                        --right;
                    }
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
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = solution.fourSum(nums, target);
    for (const auto &vec : result)
    {
        for (const auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 4Sum


#include "General.h"

class Solution
{
private:
    int state(int num, int target)
    {
        int result = 0;
        if (num < target)
            result = -1;
        else if (num == target)
            result = 0;
        else if (num > target)
            result = 1;
        return result;
    }

public:
    vector<vector<int>> threeSum(vector<int> nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int curr_sum = nums[i] + nums[j] + nums[k];
                switch (state(curr_sum, target))
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

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            auto temp_result = threeSum(vector<int>(nums.begin() + i, nums.end()), target - nums[i]);

            for (auto &vec : temp_result)
            {
                vec.push_back(nums[i]);
            }
            result.insert(result.end(), temp_result.begin(), temp_result.end());
        }
        return result;
    }
};
*/
