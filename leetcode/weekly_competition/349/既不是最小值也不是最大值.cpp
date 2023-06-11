#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1 || n == 2) return -1;
        else {
        	return nums[1];
        }
    }
};