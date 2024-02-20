/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include "General.h"

// @lc code=start

struct Compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i : nums)
        {
            if (m.find(i) == m.end())
            {
                m[i] = 1;
            }
            else
            {
                m[i]++;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (const auto &pair : m)
        {
            pq.push(pair);
        }

        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{

    return 0;
}
