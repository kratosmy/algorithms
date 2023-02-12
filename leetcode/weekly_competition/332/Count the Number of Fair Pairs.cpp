#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    typedef long long LL;

    long long count(vector<int>& nums, int upper) {
        LL cnt = 0;
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            LL sum = nums[left] + nums[right];
            if (sum <= upper) {
                cnt += right - left;
                left += 1;
            } else right -= 1;
        }

        return cnt;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        LL l_cnt = count(nums, lower - 1);
        LL r_cnt = count(nums, upper);
        return r_cnt - l_cnt;
    }
};