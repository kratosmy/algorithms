#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ans = 0, init = 0, n = nums.size();

        for (int i = n - 1; i >= 0; i --) {
            if (nums[i] > init) init = nums[i];
            else init += nums[i];
            ans = max(ans, init);
        }

        return ans;
    }
};