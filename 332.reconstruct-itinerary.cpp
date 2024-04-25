/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */
#include "General.h"

// @lc code=start
class Solution
{
private:
    unordered_map<string, multiset<string>> target;
    vector<string> route;

    void visit(const string& airport)
    {
        while (!target[airport].empty())
        {
            string next = *target[airport].begin();
            target[airport].erase(target[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto& ticket: tickets)
        {
            target[ticket[0]].insert(ticket[1]);
        }
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;

    vector<vector<string>> tickets2 = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    vector<string> result2 = solution.findItinerary(tickets2);
    cout << "Test 2 result: ";
    for (const string &stop : result2)
    {
        cout << stop << " ";
    }
    cout << endl;

    return 0;
}
