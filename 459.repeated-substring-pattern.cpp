/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

#include "General.h"

// @lc code=start
class Solution {
private:
    vector<int> lps;
    void genLps(string s)
    {
        this->lps = vector<int>(s.size(), 0);
        int len = 0;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[len] == s[i])
            {
                len++;
                this->lps[i] = len;
            }
            else
            {
                while (len > 0 && s[len] != s[i])
                {
                    len = lps[len - 1];
                }
                if (s[len] == s[i])
                {
                    len++;
                }
                this->lps[i] = len;
            }
        }
    }
public:
    bool repeatedSubstringPattern(string s) 
    {
        this->genLps(s);
        int last = s.size() - this->lps[s.size() - 1];
        if (last == 0 || last == s.size() || s.size() % last != 0)
        {
            return false;
        }
        string pattern = s.substr(0, last);
        int pointer = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != pattern[pointer])
            {
                return false;
            }
            pointer = (pointer + 1) % last;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.repeatedSubstringPattern("abac");
    return 0;
}


