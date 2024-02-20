/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */
#include "General.h"

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sc;
        for(char c: s)
        {
            if (sc.empty() || sc.top() != c)
            {
                sc.push(c);
            }
            else
            {
                sc.pop();
            }
        }
        string result = "";
        while (!sc.empty())
        {
            result += sc.top();
            sc.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.removeDuplicates("abbaca");
    return 0;
}

