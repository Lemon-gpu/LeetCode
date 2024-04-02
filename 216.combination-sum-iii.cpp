/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] Combination Sum III
 */
#include "General.h"

// @lc code=start
class Solution {
private:
    vector<int> currResult;
    vector<vector<int>> result;
    vector<int> numList;
    void search(int k, int n, int startIndex)
    {
        if (n < 0 || (k == 0 && n != 0)) { return; }
        if (k == 0 && n == 0) { result.push_back(currResult); return; }
        for (; startIndex < 9; startIndex++)
        {
            int& value = numList[startIndex];
            if (numList[startIndex] == -1) { continue; }
            currResult.push_back(value);
            search(k - 1, n - value, startIndex + 1);
            currResult.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        for (int i = 1; i <= 9; i++) { numList.push_back(i); }
        search(k, n, 0);
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    s.combinationSum3(3, 7);
    return 0;
}


