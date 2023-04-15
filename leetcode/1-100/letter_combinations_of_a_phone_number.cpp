#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> res;
    string ref[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        dfs(digits, 0, "");
        return res;
    }

    void dfs(string& digits, int len, string path) {
        if (len == digits.size()) res.push_back(path);
        else {
            for (auto& c : ref[digits[len] - '0']) {
                dfs(digits, len + 1, path + c);
            }
        }
    }
};