#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < l; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < l; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                for (int k = j + 1, u = l - 1; k < u; k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    while (u - 1 > k && (long) nums[i] + nums[j] + nums[k] + nums[u - 1] >= target) u--;
                    if ((long) nums[i] + nums[j] + nums[k] + nums[u] == target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[u]});
                    }
                }
            }
        }
        return res;
    }
};