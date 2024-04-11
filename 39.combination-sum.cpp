/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] Combination Sum
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
        if (target == 0) { result.push_back(tempResult); }

        for (int i = left; i < candidates.size(); i++)
        {
            if (target < candidates[i]) { break; }
            tempResult.push_back(candidates[i]);
            search(candidates, target - candidates[i], i);
            tempResult.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        search(candidates, target, 0);
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    for (auto& vec : result)
    {
        for (auto& num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

