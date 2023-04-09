#include <vector>

using namespace std;

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (isPrime(nums[i][i])) res = max(res, nums[i][i]);
            if (isPrime(nums[i][nums.size() - i - 1])) res = max(res,  nums[i][nums.size() - i - 1]);
        }
        return res;
    }

    bool isPrime(int n) {
        if (n == 1) return false;
        for(int i = 2; i * i <= n; i ++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }
};