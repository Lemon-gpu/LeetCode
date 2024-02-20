/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

#include "General.h"

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        s = simplify(s);
        t = simplify(t);
        return s == t;
    }

    string simplify(string s) 
    {
        int slow = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
            {
                slow = backspace(slow);
            }
            else 
            {
                slow++;
                s[slow] = s[i];
            }
        }
        return slow == -1 ? "" : s.substr(0, slow + 1);
    }

    int backspace(int slow) 
    {
        slow--;
        return slow < -1 ? -1 : slow;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    cout << s.backspaceCompare("a#c", "b");
    return 0;
}




