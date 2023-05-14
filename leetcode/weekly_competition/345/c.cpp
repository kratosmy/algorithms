#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans = 0;
    unordered_map<vector<int, int>, int> heap;

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i ++) {
            dfs(grid, i, 0, m, n, 0);
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n, int cnt) {
        vector<vector<int>> direction = {{-1, 1}, {0, 1}, {1, 1}};

        for (auto d : direction) {
            int r_n = r + d[0];
            int c_n = c + d[1];
            if (heap[{r_n, c_n}]) return;
            if (r_n >= m || r_n < 0 || c_n >= n || c_n < 0 || grid[r_n][c_n] <= grid[r][c]) {
                heap[{r_n, c_n}] ++;
                ans = max(ans, cnt);
                continue;
            } else {
                dfs(grid, r_n, c_n, m, n, cnt + 1);
            }
        }
    }
};
