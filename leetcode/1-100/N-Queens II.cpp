#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<bool> col, dg, rdg;
    vector<string> path;
    vector<vector<string>> ans;
    int n;

    int totalNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = rdg = vector<bool>(n * 2);
        path = vector<string>(n, string(n, '.'));

        dfs(0);
        return ans.size();
    }

    void dfs(int u) {
        if (u == n) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u - i + n] && !rdg[u + i]) {
                col[i] = dg[u - i + n] = rdg[u + i] = true;
                path[u][i] = 'Q';
                dfs(u + 1);
                path[u][i] = '.';
                col[i] = dg[u - i + n] = rdg[u + i] = false;
            }
        }
    }
};