#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int esum = 0;
        int nsum = 0;

        for (int i = 0; i < nums.size(); i++) {
            esum += nums[i];
            nsum += num_sum(nums[i]);
        }

        return abs(esum - nsum);
    }

    int num_sum(int& n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n = n / 10;
        }
        return res;
    }
};