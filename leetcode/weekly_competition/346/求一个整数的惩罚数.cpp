#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(string s, int sum, int x, int i) {
        if (sum == x && i == s.size()) return true;
        for (int j = i; j < s.size(); j ++) {
            int cur = stoi(s.substr(i, j - i + 1));
            sum += cur;
            if (sum > x) break;
            if (dfs(s, sum, x, j + 1)) return true;
            sum -= cur;
        }
        return false;
    }

    bool judge(int x) {
        if (x * x == x) return true;
        string s = to_string(x * x);
        return dfs(s, 0, x, 0);
    }

    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            if (judge(i)) res += (i * i);
        }
        return res;
    }
};