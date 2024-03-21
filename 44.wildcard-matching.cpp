/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
#include "General.h"

// @lc code=start
class Solution {
private:
    vector<vector<bool>> state;
    bool containOnly(const string s, char c = '*')
    {
        bool result = true;
        for (char sc: s)
        {
            if (sc != c)
            {
                result = false;
                break;
            }
        }
        return result;
    }

    void init(const string& s, const string& p)
    {
        state = vector<vector<bool>>(s.size() + 1, vector<bool>(p.size() + 1)); // state[i][j] indicate that whether the top-i (include i) string match or not under the condition of pattern top-j (include j)
        state[0][0] = true; // empty string match with empty pattern

        /*
        for (int i = 0; i < state.size(); i++)
        {
            state[i][0] = false; // any string doesn't match with empty pattern, and in fact this can be ignore as the initialization have done this to us
        }
        */

        /*
        for (int j = 0; j < state[0].size(); j++)
        {
            if (containOnly(p.substr(0, j + 1))) // empty string only match with all '*' pattern;
            {
                state[0][j] = true;
            }
            else // otherwise it would fail to match
            {
                state[0][j] = false;
            }
        }
        */

       // a simpler vision is this
       for (int j = 1; j < state[0].size(); j++)
       {
            if (p[j - 1] == '*')
            {
                state[0][j] = state[0][j - 1];
            }
       }
    }
    
public:
    bool isMatch(string s, string p) 
    {
        init(s, p);
        for (int i = 1; i < state.size(); i++)
        {
            for (int j = 1; j < state[0].size(); j++)
            {
                if (p[j - 1] == '*')
                {
                    state[i][j] = state[i - 1][j] || state[i][j - 1];
                }
                else 
                {
                    if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                    {
                        state[i][j] = state[i - 1][j - 1];
                    }
                }
            }
        }

        return state[s.size()][p.size()];

    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution so;
    string s = "aa", p = "aa";
    cout << so.isMatch(s, p);
    return 0;
}

