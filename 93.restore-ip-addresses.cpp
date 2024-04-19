/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */
#include "General.h"

// @lc code=start
class Solution {
private:
    vector<string> result;
    vector<string> tempResult;

    string combine()
    {
        string s;
        for (string tS: tempResult)
        {
            s += (tS + ".");
        }
        s.pop_back();
        return s;
    }
    
    bool verify(string s)
    {
        if (s.size() > 1 && s[0] == '0') { return false; }
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    void search(string s, int blocks)
    {
        if (blocks == 0 && s.empty()) { result.push_back(combine()); return; }
        if (s.size() > blocks * 3 || s.size() < blocks * 1) { return; }

        for (int i = 0; i < 3 && i < s.size(); i++)
        {
            string a = s.substr(0, i + 1);
            if (!verify(a)) { break; }

            string b = s.substr(i + 1);

            tempResult.push_back(a);
            search(b, blocks - 1);
            tempResult.pop_back();
        }

    }
public:
    vector<string> restoreIpAddresses(string s) {
        search(s, 4);
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.restoreIpAddresses("101023");
    for (string s: result)
    {
        cout << s << endl;
    }
    return 0;
}


