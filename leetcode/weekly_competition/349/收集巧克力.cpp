#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        vector<long long> sum;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i ++) sum.push_back((long long) i * x);

        for (int i = 0; i < nums.size(); i ++) {
        	int mn = nums[i];
        	for (int j = i; j < n + i; j ++) {
        		mn = min(mn, nums[j % n]);
        		sum[j - i] += mn;
        	}
        }
        return *min_element(sum.begin(), sum.end());	
    }
};