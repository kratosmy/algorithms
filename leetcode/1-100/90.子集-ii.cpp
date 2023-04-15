/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    unordered_map<int, int> cnt;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for (auto x : nums) cnt[x] ++;
        dfs(-10);
        return ans;
    }

    void dfs(int u) {
        if (u > 10) ans.push_back(path);
        else {
            for (int i = 0; i < cnt[u] + 1; i ++) {
                dfs(u + 1);
                path.push_back(u);
            }

            for (int i = 0; i < cnt[u] + 1; i ++) {
                path.pop_back();
            }
        }
    }
};
// @lc code=end

