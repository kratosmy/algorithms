#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int min_p, max_p = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 1) min_p = i;
            if (nums[i] == n) max_p = i;
        } 
        
        if (min_p < max_p) return min_p + (n - 1 - max_p);
        else return min_p + (n - 1 - max_p) - 1;
    }
};