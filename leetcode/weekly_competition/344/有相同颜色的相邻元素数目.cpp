#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int nums[n];
        vector<int> ans;

        memset(nums, 0, sizeof(nums));
        int cnt = 0;
        for (auto& q : queries) {
        	int idx = q[0];
        
    		if (idx - 1 >= 0 && nums[idx] == nums[idx - 1] && nums[idx] != 0) cnt --;
    		if (idx + 1 < n && nums[idx] == nums[idx + 1] && nums[idx] != 0) cnt --;
        	
        	int color = q[1];
        	nums[idx] = color;

        	if (idx - 1 >= 0 && nums[idx] == nums[idx - 1] && nums[idx] != 0) cnt ++;
    		if (idx + 1 < n && nums[idx] == nums[idx + 1] && nums[idx] != 0) cnt ++;

        	ans.push_back(cnt);
        }
        return ans;
    }
};