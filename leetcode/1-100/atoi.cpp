#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int k = 0;
        while (k < s.size()) {
            if (s[k] == ' ') k++;
            else break;
        }
        if (k == s.size()) return 0; 

        int minus = 1;
        if (s[k] == '-') minus = -1, k++;
        else if (s[k] == '+') k++;

        int res = 0;
        while (k < s.size() && s[k] >= '0' && s[k] <= '9') {
            int x = s[k] - '0';
            if (minus == 1 && res > (INT_MAX - x) / 10) return INT_MAX;
            else if (minus == -1 && -res < (INT_MIN + x) / 10) return INT_MIN;
            else if (minus == -1 && -res * 10 - x == INT_MIN) return INT_MIN;
            res = res * 10 + x;
            k++;
        }
        return res * minus;
    }
};