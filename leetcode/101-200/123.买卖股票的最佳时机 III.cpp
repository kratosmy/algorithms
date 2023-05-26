#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n + 1);
        for (int i = 1, min_p = INT_MAX; i <= n; i ++) {
            f[i] = max(f[i - 1], prices[i - 1] - min_p);
            min_p = min(min_p, prices[i - 1]);
        }

        int res = 0;
        for (int i = n, max_p = 0; i; i --) {
            res = max(res, f[i - 1] + max_p - prices[i - 1]);
            max_p = max(max_p, prices[i - 1]);
        }
        
        return res;
    }
};