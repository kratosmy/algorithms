#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string s = words[i];
            sort(s.begin(), s.end());
            s.erase(unique(s.begin(), s.end()), s.end());
            ans += mp[s];
            mp[s]++;
        }
        return ans;
    }
};