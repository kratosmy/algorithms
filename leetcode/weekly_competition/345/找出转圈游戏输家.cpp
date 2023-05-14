#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> ans;
        vector<int> p(n, 0);
        int r = 0;
        int c = 0;

        while (true) {
            c = (c + r * k) % n;
            p[c] += 1;
            r += 1;
            if (count(p.begin(), p.end(), 2)) break;
        }

        for (int i = 0; i < n; i ++) {
            if (p[i] == 0) ans.push_back(i + 1);
        }

        return ans;
    }
};