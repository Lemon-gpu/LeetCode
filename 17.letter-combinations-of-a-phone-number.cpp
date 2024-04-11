/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include "General.h"

// @lc code=start
class Solution {
private:
    vector<string> table = 
    {
        "", 
        "", "abc", "def", 
        "ghi", "jkl", "mno", 
        "pqrs", "tuv", "wxyz"
    };
    vector<string> result;

    void search(string& digits, string& tempResult)
    {
        if (digits.empty()) { result.push_back(tempResult); return; }

        int index = digits.back() - '0'; // 反正是单个数
        digits.pop_back();

        for (char c: table[index])
        {
            tempResult.push_back(c);
            search(digits, tempResult);
            tempResult.pop_back();
        }

        digits.push_back(char(index + '0'));
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {return result;}
        reverse(digits.begin(), digits.end());
        string tempResult = "";
        search(digits, tempResult);
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.letterCombinations("23");
    for (auto ss: result)
    {
        cout << ss << endl;
    }
    return 0;
}

