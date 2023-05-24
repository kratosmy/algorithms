#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0, min_p = INT_MAX; i < prices.size(); i ++) {
            res = max(res, prices[i] - min_p);
            min_p = min(min_p, prices[i]);
        }
        return res;
    }
};