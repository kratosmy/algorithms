#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<PII> all;
        all.push_back({-2, 1});
        all.push_back({2, -1});
        all.push_back({-2, -1});
        all.push_back({2, 1});
        all.push_back({1, 2});
        all.push_back({1, -2});
        all.push_back({-1, 2});
        all.push_back({-1, -2});
        int temp = grid[0][0];
        if (temp != 0) return false;

        int col = 0, row = 0;
        unordered_map<int, PII> ref = choice(grid, col, row, n, all);
        while (ref.size() && ref.find(temp + 1) != ref.end() && temp < n * n) {
            col = ref[temp + 1].first;
            row = ref[temp + 1].second;
            temp += 1;
            ref = choice(grid, col, row, n, all);
        }
        return temp == n * n - 1;
    }

    unordered_map<int, pair<int, int>> choice(vector<vector<int>>& grid, int raw_col, int raw_row, int n, vector<PII> all) {
        unordered_map<int, pair<int, int>> ref;
        for (auto& pair : all) {
            int col, row;
            col = raw_col + pair.first;
            row = raw_row + pair.second;
            if (n - 1 >= col && col>= 0 && n - 1 >= row && row >= 0) {
                ref[grid[col][row]] = {col, row};
            }
        }
        return ref;
    }
};