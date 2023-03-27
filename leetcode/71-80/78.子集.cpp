#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int start) {
        res.push_back(path);
        if (start >= nums.size()) {
            return;
        }

        for (int i = start; i < nums.size(); i ++) {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
};

