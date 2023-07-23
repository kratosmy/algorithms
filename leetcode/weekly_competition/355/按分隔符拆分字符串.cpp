#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;

        for (auto word : words) {
            stringstream ss(word);
            string token;
            while (getline(ss, token, separator)) {
                if (token != "") ans.push_back(token);
            }
        }

        return ans;
    }
};