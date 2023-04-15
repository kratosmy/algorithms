#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& ma) {
        if (ma.empty() || ma[0].empty()) return;
        int m = ma.size(), n = ma[0].size();

        int r0 = 1, c0 = 1;
        for (int i = 0; i < m; i ++) {
            if (ma[i][0] == 0) c0 = 0;
        }

        for (int i = 0; i < n; i ++) {
            if (ma[0][i] == 0) r0 = 0;
        }

        for (int i = 1; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (ma[i][j] == 0) ma[i][0] = 0;
            }
        }

        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (ma[j][i] == 0) ma[0][i] = 0;
            }
        }

        for (int i = 1; i < m; i ++) {
            if (ma[i][0] == 0) {
                for (int j = 0; j < n; j ++) {
                    ma[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i ++) {
            if (ma[0][i] == 0) {
                for (int j = 0; j < m; j ++) {
                    ma[j][i] = 0;
                }
            }
        }

        if (!r0) {
            for (int i = 0; i < n; i ++) ma[0][i] = 0;
        }

        if (!c0) {
            for (int i = 0; i < m; i ++) ma[i][0] = 0;
        }
    }
};
