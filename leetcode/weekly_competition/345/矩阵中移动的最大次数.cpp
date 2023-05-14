#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans = 0;

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));

        for (int i = 0; i < m; i ++) {
            dfs(grid, i, 0, 0, visit);
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int cnt, vector<vector<bool>>& visit) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> direction = {{-1, 1}, {0, 1}, {1, 1}};
        
        for (auto d : direction) {
            int r_n = r + d[0];
            int c_n = c + d[1];

            if (r_n >= m || r_n < 0 || c_n >= n || c_n < 0 || grid[r_n][c_n] <= grid[r][c]) {
                ans = max(ans, cnt);
                continue;
            } else {
                if (visit[r_n][c_n]) continue;
                visit[r_n][c_n] = true;
                dfs(grid, r_n, c_n, cnt + 1, visit);
            }
        }
    }
};
