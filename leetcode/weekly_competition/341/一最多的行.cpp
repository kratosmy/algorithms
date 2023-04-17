#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        unordered_map<int, int> cnt;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i ++) {
            cnt[i] = accumulate(mat[i].begin(), mat[i].end(), 0);
        }

        int l = 0;
        int r = 0;
        for (auto it : cnt) {
            if (it.second > r) {
                l = it.first;
                r = it.second;
            } else if (it.second == r) {
                l = min(l, it.first);
            }
        }

        return {l, r};
    }
};