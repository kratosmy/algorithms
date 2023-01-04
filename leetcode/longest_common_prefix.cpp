#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()) return res;

        for (int i = 0;; i++) {
            char c = strs[0][i];
            for (auto &str : strs) {
                if (i >= str.size() || c != str[i]) {
                    return res;
                }
            }
            res += c;
        }
    }
};