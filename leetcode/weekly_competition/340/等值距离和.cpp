#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    typedef long long LL;
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<LL> arr(n);
        unordered_map<int, vector<LL>> ref;

        for (int i = 0; i < n; i ++) {
            ref[nums[i]].push_back(i);
        }

        for (auto& it : ref) {
            vector<LL> sub_arr = it.second;
            int m = it.second.size();
            vector<LL> sum(m);
            sum[0] = sub_arr[0];
            for (int i = 1; i < m; i ++) {
                sum[i] = sum[i - 1] + sub_arr[i];
            }

            for (int i = 0; i < m; i ++) {
                if (i == 0) {
                    arr[sub_arr[i]] = sum[m - 1] - sum[i] * m;
                    continue;
                }
                LL l = sub_arr[i] * i - sum[i - 1];
                LL r = sum[m - 1] - sum[i] - (m - i - 1LL) * sub_arr[i];
                arr[sub_arr[i]] = l + r;
            }
        }

        return arr;
    }
};