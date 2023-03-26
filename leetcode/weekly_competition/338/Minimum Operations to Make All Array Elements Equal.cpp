#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<LL> res, psum(n + 1);
    
        for (int i = 1; i <= n; i ++) psum[i] = psum[i - 1] + nums[i - 1];

        for (LL q : queries) {
            LL idx = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            LL small = idx, large = n - idx;
            LL cnt = q * small - psum[idx] + (psum[n] - psum[idx]) - q * large;
            res.push_back(cnt);
        }

        return res;
    }
};
