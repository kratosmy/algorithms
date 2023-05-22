#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> layer_1 = {1};
        vector<int> layer_2 = {1, 1};
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};

        else {
            res.push_back(layer_1);
            res.push_back(layer_2);

            for (int i = 2; i < numRows; i ++) {
                vector<int> layer_cur;
                layer_cur.push_back(1);
                for (int j = 0; j < res[i - 1].size() - 1; j ++) {
                    layer_cur.push_back(res[i - 1][j] + res[i - 1][j + 1]);
                }
                layer_cur.push_back(1);
                res.push_back(layer_cur);
            }
        }
        return res;
    }
};