/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */
#include "General.h"

// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;

    void search(vector<int> &nums, vector<int> &tempResult, int left)
    {
        if (tempResult.size() > 1)
        {
            if (tempResult[tempResult.size() - 1] >= tempResult[tempResult.size() - 2])
            {
                result.push_back(tempResult);
            }
            else
            {
                return;
            }
        }

        unordered_set<int> used;
        for (int i = left; i < nums.size(); i++)
        {
            if (used.find(nums[i]) != used.end())
            {
                continue;
            }
            used.insert(nums[i]);
            tempResult.push_back(nums[i]);
            search(nums, tempResult, i + 1);
            tempResult.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> v;
        search(nums, v, 0);
        return result;
    }
};
// @lc code=end

#include <cassert>
#include <vector>

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 1};
    vector<vector<int>> result = sol.findSubsequences(nums);
    cout << '[' << endl;
    for (vector<int> ve : result)
    {
        cout << "  [";
        for (int i : ve)
        {
            cout << i << ", ";
        }
        cout << "]," << endl;
    }
    cout << ']' << endl;
    return 0;
}
