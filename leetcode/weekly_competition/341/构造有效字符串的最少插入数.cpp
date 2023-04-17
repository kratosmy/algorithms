#include <string>

using namespace std;

class Solution {
public:
    int addMinimum(string s) {
        int t = s[0] - s.back() + 2;
        int ans = 0;
        for (int i = 1; i < s.size(); i ++) {
            ans += (s[i] - s[i - 1] + 2) % 3;
        }
        return ans + t;
    }
};