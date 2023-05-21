#include <cmath>

using namespace std;

class Solution {
public:
    bool dfs(int x, int ref, int l) {
        if (x == ref) return true; 
        for (int i = 1; i <= l; i ++) {
            dfs(x - ref / (pow(10, i)), ref % (int)(pow(10, i)), l);
        }
        return false;
    }

    bool judge(int x) {
        int ref = x * x;
        return dfs(x, ref, floor(log10(ref)) + 1);
    }

    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            if (judge(i)) res += (i * i);
        }
        return res;
    }
};