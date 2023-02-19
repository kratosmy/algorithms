#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(int m) {
        int k = 0;

        while (pow(2, k) < m) k++;

        if (pow(2, k) == m) return 1;
        else {
            return 1 + minOperations(min(m - pow(2, k - 1), pow(2, k) - m));
        }
    }
};