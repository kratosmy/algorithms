#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        dfs(c, 0, target);    
        return ans;
    }

    void dfs(vector<int>& c, int u, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (u == c.size()) return;

        int j = u + 1;
        while (j < c.size() && c[j] == c[u]) j ++;
        int k = j - u;

        for (int i = 0; i <= k && c[u] * i <= target; i++) {
            dfs(c, j, target - c[u] * i);
            path.push_back(c[u]);
        }

        for (int i = 0; i <= k && c[u] * i <= target; i++) {
            path.pop_back();
        }
    }    
};