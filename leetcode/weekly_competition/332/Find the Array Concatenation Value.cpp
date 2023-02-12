#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        typedef long long LL;
        LL res = 0;
    
        while (nums.size() > 1) {
            int n = nums.size();
            res += (stoi(to_string(nums[0]) + to_string(nums[n - 1])));
            nums.pop_back();
            nums.erase(nums.begin());
        }
        
        if (nums.size() == 1) res += nums[0];
        
        return res;
    }
};