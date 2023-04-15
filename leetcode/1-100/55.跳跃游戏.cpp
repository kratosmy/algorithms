#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (j < i) return false;
            j = max(j, nums[i] + i);
        }
        return true;
    }
};

