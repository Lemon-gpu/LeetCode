/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */
#include "General.h"

// @lc code=start
class Solution {
private:
    vector<vector<string>> result;
    vector<string> currResult;
    vector<string> table;

    bool isPalindrome(const string& s)
    {
        bool result = true;

        int left = 0;
        int right = s.size() - 1;
        while (right > left)
        {
            if (s[left++] != s[right--]) 
            {
                result = false;
                break;
            }
        }

        return result;
    }
    vector<string> splitAll(const string& s)
    {
        vector<string> result;
        for (char c: s)
        {
            result.push_back(string(1, c));
        }
        return result;
    }

    void search(const vector<string>& table, int left)
    {
        if (left == table.size() && !this->currResult.empty())
        {
            this->result.push_back(currResult);
            return;
        }

        string tempResult;
        for (int i = left; i < table.size(); i++)
        {
            tempResult += table[i];
            if (isPalindrome(tempResult))
            {
                this->currResult.push_back(tempResult);
                search(table, i + 1);
                currResult.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        this->table = splitAll(s);
        search(this->table, 0);
        return this->result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<string>> result = s.partition("aab");
    for (auto& vec: result)
    {
        for (auto& str: vec)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
