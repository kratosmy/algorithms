#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans = -1;
    int n;
    int target;
    vector<int> nums;
    vector<int> vis;

    int maximumJumps(vector<int>& _nums, int _target) {
        nums = _nums;
        target = _target;
        n = nums.size();
        vis = vector<int>(n, 0);
        dfs(0, 0);

        return ans;
    }

    void dfs(int u, int step) {
        if (u == n - 1) {
            ans = max(ans, step);
            return;
        }

        for (int i = u + 1; i < n; i ++) {
            if (abs(nums[i] - nums[u]) <= target && vis[i] < step + 1) {
                vis[i] = step + 1;
                dfs(i, step + 1);
            }
        }
    }
};