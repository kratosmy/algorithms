#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), k = s3.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
        
        if (m + n != k) return false;

        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (!i && !j) f[i][j] = true;
                else {
                    if (i && s1[i] == s3[i + j]) {
                        f[i][j] = f[i - 1][j];
                    }
                    if (j && s2[j] == s3[i + j]) {
                        f[i][j] = f[i][j] || f[i][j - 1];
                    }
                }
            }
        }
        return f[m][n]; 
    }
};

