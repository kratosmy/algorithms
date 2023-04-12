#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        int n = s1.size();
        vector<vector<vector<bool>>> f(n, vector<vector<bool>>(n, vector<bool>(n + 1)));

        for (int k = 1; k <= n; k ++) {
            for (int i = 0; i + k - 1 < n; i ++) {
                for (int j = 0; j + k - 1 < n; j ++) {
                    if (k == 1) {
                        if (s1[i] == s2[j]) f[i][j][k] = true;
                    } else {
                        for (int u = 1; u < k; u ++) {
                            if (f[i][j][u] && f[i + u][j + u][k - u]
                                || f[i][j + k - u][u] && f[i + u][j][k - u]) {
                                    f[i][j][k] = true;
                                    break;
                                }
                        }
                    }
                }
            }
        }
        return f[0][0][n];
    }
};

