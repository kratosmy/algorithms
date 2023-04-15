#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int x, int y) {
        typedef long long ll;
        vector<ll> exp;
        ll res = 0;
        bool is_minus = false;
        if (x < 0 && y > 0 || x > 0 && y < 0) is_minus = true;
        ll a = abs((ll)x), b = abs((ll)y);

        for (ll i = b; i <= a; i = i + i) exp.push_back(i);

        for (int i = exp.size() - 1; i >= 0; i--) {
            if (a >= exp[i]) {
                a -= exp[i];
                res += 1ll << i;
            }
        }

        if (is_minus) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;

        return res;
    }
};