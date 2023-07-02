#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int n = nums.size();

        for (int l = 0, r = 0; l < n, r < n; r ++) {
            if (nums[l] % 2 != 0) {
                l = l + 1;
            }

            if (r > l && (nums[r] % 2) == (nums[r - 1] % 2)) {
                l = r;
            }

            if (nums[r] > threshold) {
                l = r + 1;
            }
            
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};