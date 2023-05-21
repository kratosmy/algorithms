#include <string>

using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int len = s.size();

        for (int i = 0; i < len; i ++) {
            if (s[i] != s[len - i - 1]) {
                if (s[i] - 'a' > s[len - i - 1] - 'a') s[i] = s[len - i - 1];
                else s[len - i - 1] = s[i];
            }
        }

        return s;
    }
};