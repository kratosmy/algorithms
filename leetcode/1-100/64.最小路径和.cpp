#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (!n) return 0;

        int m = grid[0].size();
        vector<vector<int>> f(n, vector<int>(m));

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (!i && !j) f[i][j] = grid[i][j];
                else {
                    if (i && j) f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
                    else if (i) f[i][j] = f[i - 1][j] + grid[i][j];
                    else if (j) f[i][j] = f[i][j - 1] + grid[i][j];
                }
            }
        }
        return f[n - 1][m - 1];
    }
};

