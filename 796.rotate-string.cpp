/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] Rotate String
 */
#include "General.h"

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        /*
        if (s.size() != goal.size())
        {
            return false;
        }
        bool result = false;
        for (int target = 0; target < s.size(); target++)
        {
            if (goal[target] == s[0])
            {
                int temp_target = target;
                int i = 0;
                for (i; i < s.size(); i++)
                {
                    if (s[i] != goal[temp_target])
                    {
                        result = false;
                        break;
                    }
                    else
                    {
                        temp_target = (temp_target + 1) % int(goal.size());
                    }
                }
                if (i == s.size())
                {
                    result = true;
                    break;
                }
            }
        }
        return result;
        */
       return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


