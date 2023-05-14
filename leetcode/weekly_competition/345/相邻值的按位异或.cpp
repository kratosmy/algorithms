#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived[0];
        for (int i = 1; i < derived.size(); i ++) {
            n ^= derived[i];
        }
        return n == 0;
    }
};