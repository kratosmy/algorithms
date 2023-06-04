#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_map<char, int> hash;

        for (auto c : s) {
            hash[c] ++;
        }

        return hash.size();
    }
};