#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> ans;

        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i ++) {
            hash[nums[i]] ++;
        }

        for (int i = 0; i < nums.size(); i ++) {
            int left = 0;
            int right = 0;
            auto hash_l = hash;
            auto hash_r = hash;
            for (int j = 0; j <= i; j ++) {
                if (hash_l[nums[j]]) left ++, hash_l[nums[j]] = 0;
            }

            for (int j = i + 1; j < nums.size(); j ++) {
                if (hash_r[nums[j]]) right ++, hash_r[nums[j]] = 0;
            }

            ans.push_back(left - right);
        }

        return ans;
    }
};