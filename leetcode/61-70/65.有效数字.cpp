#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int l = 0, r = s.size() - 1;
        while (s[l] == ' ') l ++;
        while (s[r] == ' ') r --;
        if (l > r) return false;
        s = s.substr(l, r - l + 1);
        if (s[0] == '+' || s[0] == '-') s = s.substr(1);
        if (s.empty()) return false;

        if (s[0] == '.' && (s.size() == 1 || s[1] == 'e' || s[1] == 'E')) return false;

        int dot = 0, e = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '.') {
                if (dot > 0 || e > 0) return false;
                dot ++;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!i || i + 1 == s.size() || e > 0) return false;
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    if (i + 2 == s.size()) return false;
                    i ++;
                }
                e ++;
            } else if (s[i] < '0' || s[i] > '9') return false;
        }
        return true;
    }
};

