#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        // consider case when s and p are both empty.
        if (p.empty() && s.empty()) return 0;
        
        s = ' ' + s, p = ' ' + p;
        // calculate NEXT array, consider s as p.
        vector<int> next(m + 1);
        for (int i = 2, j = 0; i <= m; i++) {
            while (j && p[i] != p[j + 1]) j = next[j];
            if (p[i] == p[j + 1]) j++;
            next[i] = j;
        } 

        for (int i = 1, j = 0; i <= n; i++) {
            while (j && s[i] != p[j + 1]) j = next[j];
            if (s[i] == p[j + 1]) j++;
            if (j == m) return i - m;
        }
        return -1;
    }
};