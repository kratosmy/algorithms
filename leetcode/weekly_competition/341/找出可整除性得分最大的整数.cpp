#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& n, vector<int>& d) {
        unordered_map<int, int> cnt;
        sort(d.begin(), d.end());

        for (int i = 0; i < d.size(); i ++) {
            if (i == 0) {
                for (int j = 0; j < n.size(); j ++) {
                    if (n[j] % d[i] == 0) cnt[d[i]] ++;
                }
            }
            if (i && d[i] != d[i - 1]) {
                for (int j = 0; j < n.size(); j ++) {
                    if (n[j] % d[i] == 0) cnt[d[i]] ++;
                }
            }
        }

        if (cnt.size() == 0) {
            sort(d.begin(), d.end());
            return d[0];
        }

        int score = 0;
        int res = INT_MIN;
        for (auto it : cnt) {
            if (it.second > score) {
                score = it.second;
                res = it.first;
            } else if (it.second == score) res = min(res, it.first);
        }

        return res;
    }
};