#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        int res = 0;
        vector<LL> prefix(nums.size());
        for (int i = 0; i < nums.size(); i ++) {
            if (!i) prefix[i] = nums[i];
            else prefix[i] = prefix[i - 1] + nums[i];    
        }

        for (auto& e : prefix) {
            if (e > 0) res ++;
        }

        return res;
    }
};