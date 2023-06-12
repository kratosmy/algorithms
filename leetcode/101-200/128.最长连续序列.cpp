#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	unordered_set<int> S;
    	for (auto& num : nums) S.insert(num);

    	int res = 0;
    	for (auto& num : nums) {
    		if (!S.count(num - 1)) {
    			int y = num;
    			S.erase(num);
    			while (S.count(y + 1)) {
    				y ++;
    				S.erase(y);
    			}
    			res = max(res, y - num + 1);
    		}
    	}
    	return res;
    }
};