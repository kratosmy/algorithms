#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        typedef long long LL;
        double res = 1;

        bool is_minus = false;
        if (n < 0) is_minus = true;

        for (LL k = LL(abs(n)); k; k >>= 1) {
            if (k & 1) res *= x;
            x *= x; 
        }

        if (is_minus) res = 1 / res;

        return res;
    }
};