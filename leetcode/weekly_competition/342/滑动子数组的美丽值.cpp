#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        map<int, int> cnt;
        int n = nums.size();

        for (int i = 0; i < k; i ++) {
            cnt[nums[i]] ++;
        }

        for (int i = 0; i < n - k + 1; i ++) {
            int temp = x;
            for (auto& item : cnt) {
                temp -= item.second;
                if (temp <= 0) {
                    ans.push_back(item.first < 0 ? item.first : 0);
                    break;
                }
            }
            cnt[nums[i]] --;
            if (i + k < n) cnt[nums[i + k]] ++;
        }

        return ans;
    }
};